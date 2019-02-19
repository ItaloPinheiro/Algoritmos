// Grafos - Lista de adjacência
// Criar Grafo, Add arestas, obter graus, vizinhos;
#include <iostream>
#include <list>
#include <algorithm> // função find não vinculada

using namespace std;

class Grafo
{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
	// obtém o grau de saída de um dado vértice
	// grau de saída é o número de arcos que saem de "v"
	int obterGrauDeSaida(int v);
	int obterGrauDeEntrada(int V, int v);

	bool existeVizinho(int v1, int v2); // verifica se v2 é vizinho de v1
};

Grafo::grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V+1]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}
int Grafo::obterGrauDeEntrada(int V, int v){
int cont=0;
	for(int i = 0; i < V+1; i++){
		if(find(adj[i].begin(), adj[i].end(), v) != adj[i].end())
		cont++;
	}
	return cont;
}

int Grafo::obterGrauDeSaida(int v)
{
	// basta retornar o tamanho da lista que é a quantidade de vizinhos
	return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2)
{
	if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
		return true;
	return false;
}

int main()
{
	
	// criando um grafo de 4 vértices
	int V;
	int a, b, op;
	bool duplaincidencia = false;
	cout << "Insira o numero de vertices do Grafo: "; cin >> V;
	cout << endl;
	Grafo grafo(V);
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
			 			grafo.adicionarAresta(a, b);
			 			cout << "Insira o par de vertices: "; cin >> a;
		 			} break;
			// mostrando o grau de entrada
			case 2: cout << "Digite -1 para sair !\n" <<
					"Insira o vertice: "; cin >> a;
					while(a != -1){
						cout << "O grau de entrada desse vertice eh: " << grafo.obterGrauDeEntrada(V, a) <<
						"\nInsira o vertice: "; cin >> a;
					} break;
			// mostrando o grau de saida
			case 3: cout << "Digite -1 para sair !\n" <<
					"Insira o vertice: "; cin >> a;
					while(a != -1){
						cout << "O grau de saida desse vertice eh: " << grafo.obterGrauDeSaida(a) <<
						"\nInsira o vertice: "; cin >> a;
					} break;
			// mostrando o se são vertices vizinhos
			case 4: cout << "Digite -1 para sair !\n" <<
					"Insira o vertice: "; cin >> a;
					while(a != -1){
						cin >> b;
						if(grafo.existeVizinho(a, b))
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
