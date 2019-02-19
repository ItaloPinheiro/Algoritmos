#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector < vector<int> > vec;
grafo(int V)
{
	int V1 = V; // atribui o número de vértices
	for(int i = 0; i < V1+1; i++){
		vector <int> fila;
		vec.push_back(fila);
	}
}

void adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	vec[v1].push_back(v2);
}
int obterGrauDeEntrada(int V, int v){
int cont=0;
	for(int i = 0; i < V+1; i++){
		if(find(vec[i].begin(), vec[i].end(), v) != vec[i].end())
		cont++;
	}
	return cont;
}

int obterGrauDeSaida(int v)
{
	// basta retornar o tamanho da lista que é a quantidade de vizinhos
	return vec[v].size();
}

bool existeVizinho(int v1, int v2)
{
	if(find(vec[v1].begin(), vec[v1].end(), v2) != vec[v1].end())
		return true;
	return false;
}

int main()
{
	
	// criando um grafo de 4 vértices
	int V;
	int a, b, op;
	cout << "Insira o numero de vertices do Grafo: "; cin >> V;
	cout << endl;
	grafo(V);
	// Menu de seleção
	cout << "Selecione uma opcao: \n" <<
	 "1 - Adicionar Aresta\n"<< 
	 "2 - Ver grau de entrada de um vertice\n"<<
	 "3 - Ver grau de saida de um vertice\n" << 
	 "4 - Ver se os vertices sao vizinhos\n" << 
	 "0 - Finalizar programa\n" <<
	 "ENTRADA: "; cin >> op;
	 while(op != 0){
	 	
		 switch(op){
		 	// adicionando arestas
		 	case 1: cout << "Digite -1 para sair !\n" <<
		 			"Insira o par de vertices: "; cin >> a;
		 			while(a != -1 ){
		 				cin >> b;
			 			adicionarAresta(a, b);
			 			cout << "Insira o par de vertices: "; cin >> a;
		 			} break;
			// mostrando o grau de entrada
			case 2: cout << "Digite -1 para sair !\n" <<
					"Insira o vertice: "; cin >> a;
					while(a != -1){
						cout << "O grau de entrada desse vertice eh: " << obterGrauDeEntrada(V, a) <<
						"\nInsira o vertice: "; cin >> a;
					} break;
			// mostrando o grau de saida
			case 3: cout << "Digite -1 para sair !\n" <<
					"Insira o vertice: "; cin >> a;
					while(a != -1){
						cout << "O grau de saida desse vertice eh: " << obterGrauDeSaida(a) <<
						"\nInsira o vertice: "; cin >> a;
					} break;
			// mostrando o se são vertices vizinhos
			case 4: cout << "Digite -1 para sair !\n" <<
					"Insira o vertice: "; cin >> a;
					while(a != -1){
						cin >> b;
						if(existeVizinho(a, b))
						cout << "Os vertices " << a << " e " << b << " sao vizinhos.";
						else cout << "Os vertices " << a << " e " << b << " nao sao vizinhos.";
						cout << "\nInsira os vertices: "; cin >> a;
					}
		}	
		if(!op)
	 		return 0;
		else{
			cout << "\nSelecione uma opcao: \n" << "ENTRADA: "; 
			cin >> op;
		}
	}
	return 0;
}
