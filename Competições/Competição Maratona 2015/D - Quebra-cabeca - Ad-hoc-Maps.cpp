#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;
class Var{
	public:
	string palavra;
	int qtd;
	bool acesso;
	Var cria_Var(string, int, bool);
};

Var cria_Var(string a, int num, bool acess){
	Var variavel;
	variavel.palavra = a;
	variavel.qtd = num;
	variavel.acesso = acess;
	return variavel;
}

class Eq{
	public:
	list< Var > lista;
	int valor;
	int tamanho;
	void listar(string, int);
};

void Eq::listar(string a, int num){
	lista.push_back(cria_Var(a, num, true));
}

bool compara(Eq a, Eq b){
	return a.lista.size() < b.lista.size();
}

int main(){
	int n, m, i, j, cont, pos = 0;
	int valor, n_var = 0;
	scanf("%d %d", &n, &m);
	Eq equacao;
	vector<Eq> vec(n+m);
	vector<Eq>::iterator it_vec;
	list< Var >::iterator it_list;
	map<string, int> mapa;
	map<string, int>::iterator it_map;
	pair< map<string, int>::iterator, bool> ret;
	string game[n][m], var;
	int l_res[n];
	int c_res[m];
	//recebendo e linkando as equações das linhas
	for(i = 0; i < n; i++){
        multiset<string> set;
        multiset<string>::iterator it_set;
		for(j = 0; j < m; j++){
			cin >> var;
			game[i][j] = var;
			ret = mapa.insert(make_pair(var, 0)); //todas as variaveis
			if(ret.second) n_var++;
			set.insert(var);
		}
		cont = 0;
		it_set = set.begin();
		string aux = *it_set;
		for(it_set = set.begin(); it_set != set.end(); it_set++){
			if(aux == *it_set){
				cont++;
			}else{
				vec[pos].listar(aux, cont);
				aux = *it_set;
				cont = 1;
			}
		}
		vec[pos].listar(aux, cont);
		scanf("%d", &valor);
		vec[pos].valor = valor;
		vec[pos].tamanho = vec[pos].lista.size();
		pos++;
	}
	//linkando as equações das colunas
	for(i = 0; i < m; i++){
        multiset<string> set;
        multiset<string>::iterator it_set;
		for(j = 0; j < n; j++){
			var = game[j][i];
			set.insert(var);
		}
		cont = 0;
		it_set = set.begin();
		string aux = *it_set;
		for(it_set = set.begin(); it_set != set.end(); it_set++){
			if(aux == *it_set){
				cont++;
			}else{
				vec[pos].listar(aux, cont);
				aux = *it_set;
				cont = 1;
			}
		}
		vec[pos].listar(aux, cont);
		scanf("%d", &valor);
		vec[pos].valor = valor;
		vec[pos].tamanho = vec[pos].lista.size();
		pos++;
	}

	//exibindo
	//mostrando as equações
	/*
	cout << endl << "Mostra equacoes: " << endl;
	for(i = 0; i < n+m; i++){
		cout << "Equacao " << i << endl;
		for(it_list = vec[i].lista.begin(); it_list != vec[i].lista.end(); it_list++){
			cout << it_list->palavra << " - " << it_list->qtd << " ";
		}
		cout << "valor -> " << vec[i].valor << endl;
	}
	cout << endl << "Mostra mapa: " << endl;
	//mostrando as variaveis descobertas
	for(it_map = mapa.begin(); it_map != mapa.end(); it_map++){
		cout << it_map->first << " - " << it_map->second << endl;
	}
	sort(vec.begin(), vec.end(), compara);
	cout << endl << "Depois de ordenar: " << endl;
	for(i = 0; i < n+m; i++){
		cout << "Equacao " << i << endl;
		for(it_list = vec[i].lista.begin(); it_list != vec[i].lista.end(); it_list++){
			cout << it_list->palavra << " - " << it_list->qtd << " ";
		}
		cout << "valor -> " << vec[i].valor << endl;
	}
	cout << "______________________________________________" << endl;
	*/
	
	//ordena as equações por tamanho
	sort(vec.begin(), vec.end(), compara);
	
	//lógica para resolver
	cont = 0;
	int prox_fila, qtd, aux;
	queue<int> fila;
	fila.push(0);
	while(cont < n_var){
        //cout << "fila -> " << fila.front()<< endl;
        //cout << "tamanho -> " << vec[fila.front()].tamanho << endl;
        aux = 0;
        i = 0;
		if(vec[fila.front()].tamanho == 1){
			it_list = vec[fila.front()].lista.begin();
			//cout << "----- Access list ------" << endl;
			while(!it_list->acesso){
				//cout << it_list->acesso << endl;
				if(it_list == vec[fila.front()].lista.end()){
					aux = 1;
					break;
				}
				it_list++;
			}
			//cout << "------------------------" << endl;
			if(aux) continue;
			var = it_list->palavra;
			valor = vec[fila.front()].valor;
			qtd = it_list->qtd;
			mapa[var] = valor / qtd;
			it_list->acesso = false;
			//cout << "var -> " << var << " / mapa[var] -> " << mapa[var] << endl;
			cont++;
			fila.pop();
			for(it_vec = vec.begin()+1; it_vec != vec.end(); it_vec++){
				i++;
				for(it_list = it_vec->lista.begin(); it_list != it_vec->lista.end(); it_list++){
					//cout<< "comparando: " << var << " - " << it_list->palavra << endl;
					if(var == it_list->palavra){
						it_list->acesso = false;
						it_vec->valor -= mapa[var]*it_list->qtd;
						it_vec->tamanho--;
					}
				}
				if(it_vec->tamanho == 1){
					//cout << "entrou" << endl;
					fila.push(i);
				}
				//cout << endl;
			}
		}else if(vec[fila.front()].tamanho > 1){
			//cout << endl << "Sem variaveis suficientes para resolver" << endl;
			fila.push(fila.front());
			fila.pop();
		}else{ fila.pop();}
		//system("pause");
	}
	
	//cout << endl << "Mostra mapa: " << endl;
	//mostrando as variaveis descobertas
	for(it_map = mapa.begin(); it_map != mapa.end(); it_map++){
		cout << it_map->first << " " << it_map->second << endl;
	}
	
	system("pause");
	return 0;
}

