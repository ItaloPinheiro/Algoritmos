#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

void bfs(int inicio, vector< vector<int> > g);
vector< vector<int> > insere(char inicio, char vertice, vector< vector<int> > g);
bool buscar(int posinicio, int posvertice, vector< vector<int> > g, bool busca);
void prefixa(int posinicio, vector< vector<int> > g);
void infixa(int posinicio, vector< vector<int> > g);
void posfixa(int posinicio, vector< vector<int> > g);
vector<char> saida;

int main(){
	vector< vector<int> > g;
	for(int i = 0; i <= 53; i++){
		g.push_back( vector<int>());
		g[i].push_back('|');
		g[i].push_back('|');
	}
	string OP;
	char raiz = 0;
	bool aux = true, busca;
	int posraiz, posletra;
	while(cin >> OP){
		char letra;
//		cout <<"a - " << g[27][0] << " - " << g[27][1] << endl;
//		cout <<"Z - " << g[26][0] << " - " << g[26][1] << endl;
		if(raiz < 97) posraiz = raiz - 64;
		else posraiz = raiz - 70;
		if(OP == "PREFIXA"){
			prefixa(posraiz, g);
			for(int i = 0; i < saida.size(); i++){
				cout << saida[i];
				if(i < saida.size()-1)cout << " ";
			}
			cout << endl;
			saida.clear();
		}
		else if(OP == "INFIXA"){
			infixa(posraiz, g);
			for(int i = 0; i < saida.size(); i++){
				cout << saida[i];
				if(i < saida.size()-1)cout << " ";
			}
			cout << endl;
			saida.clear();
		}
		else if(OP == "POSFIXA"){
			posfixa(posraiz, g);
			for(int i = 0; i < saida.size(); i++){
				cout << saida[i];
				if(i < saida.size()-1)cout << " ";
			}
			cout << endl;
			saida.clear();
		}
		else{
			cin >> letra;
			//inserção
			if(letra < 97) posletra = letra - 64;
			else posletra = letra - 70;
			if(OP == "I"){
				if(aux){raiz = letra; aux = false;}
				else g = insere(raiz, letra, g);
			}
			if(OP == "P"){
				busca = buscar(posraiz, posletra, g, busca);
				if(busca) cout << letra << " existe" << endl;
				else cout << letra << " nao existe" << endl;
			}
		}
	}
	return 0;
}

vector< vector<int> > insere(char inicio, char vertice, vector< vector<int> > g){
	int posvertice = 0, posinicio = 0;
	if(inicio < 97) posinicio = inicio - 64;
	else posinicio = inicio - 70;
	
//	cout <<  char(inicio) << " - " << posinicio << endl;
//   cout << "vertice rodando no insere -> " << char(vertice) << endl;
	
	if(vertice < inicio){
		if(g[posinicio][0] == '|'){
			if(vertice < 97){posvertice = vertice - 64;}
			else{ posvertice = vertice - 70;}
			g[posinicio][0] = posvertice;
		}else{
			if(g[posinicio][0] < 27)
		 	g = insere(g[posinicio][0]+64, vertice, g);
		 	else g = insere(g[posinicio][0]+70, vertice, g);
		}
	}else if(vertice > inicio){
		if(g[posinicio][1] == '|'){
			if(vertice < 97){posvertice = vertice - 64;}
			else{ posvertice = vertice - 70;}
			g[posinicio][1] = posvertice;
		}else{
			if(g[posinicio][1] < 27)
		 	g = insere(g[posinicio][1]+64, vertice, g);
		 	else g = insere(g[posinicio][1]+70, vertice, g);
		}
	}
//	cout << "b[1] -> " << (g[posinicio][1]+70) << endl;
	return g;
}

bool buscar(int posinicio, int posvertice, vector< vector<int> > g, bool busca){
	if(posinicio != '|'){
		if(posvertice == posinicio){
			busca = true;
			return busca;
		}
		if(posvertice < posinicio)
		busca = buscar(g[posinicio][0], posvertice, g, busca);
		else busca = buscar(g[posinicio][1], posvertice, g, busca);
	}else{ busca = false;
	return busca;}
	return busca;	
}

void prefixa(int posinicio, vector< vector<int> > g){
	//cout << "entrou" << endl;
	if(posinicio != '|')
		if(posinicio < 27)
			saida.push_back(char(posinicio+64));
		else
			saida.push_back(char(posinicio+70));
	else return;		
		prefixa(g[posinicio][0], g);	
		prefixa(g[posinicio][1], g);
}

void infixa(int posinicio, vector< vector<int> > g){
	//cout << "entrou" << endl;
	if(posinicio == '|') return;
	infixa(g[posinicio][0], g);
		if(posinicio < 27)
			saida.push_back(char(posinicio+64));
		else
			saida.push_back(char(posinicio+70));	
	infixa(g[posinicio][1], g);
}

void posfixa(int posinicio, vector< vector<int> > g){
	//cout << "entrou" << endl;
	if(posinicio == '|') return;
	posfixa(g[posinicio][0], g);
	posfixa(g[posinicio][1], g);
	if(posinicio < 27)
		saida.push_back(char(posinicio+64));
	else
		saida.push_back(char(posinicio+70));	
}
