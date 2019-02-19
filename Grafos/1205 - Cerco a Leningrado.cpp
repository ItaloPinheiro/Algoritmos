#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<climits>
#include<math.h>
#include<iomanip>

using namespace std;

// Estrutura usada para implementar a lista de adjac�ncia
class Vertice{
    public:
        double w; // peso da aresta
        int ind; // identifica��o do vertice destino da aresta
        
        // Construtores
        Vertice(){};
        
        Vertice(int ind, double w){
            this->w = w;
            this->ind = ind;
        }
};


vector< vector<Vertice> > g; // Lista de Adjac�ncia.


// Vetores utilizados no algoritmo de Dijkstra

//para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
vector<int> d; // Vetor que armazena o peso da aresta usada para alcan�ar o v�rtice.
vector<bool> cor; // Define se cada vertice ja foi encontrado ou n�o.
vector<int> p; // Vetor que armazena o pai de cada vertice.

void limpar(){
	g.clear();
	cor.clear();
	d.clear();
	p.clear();
	return;
}

// Fun��o de compara��o para utilizar a estrutura heap de minimo.
// Pois a biblioteca <algorithm> tem por padr�o a implementa��o do heap de m�ximo.
bool comp(const int A, const int B)
{
    return d[A] > d[B];
}


// Algoritmo calcula a menor distancia para alcan�ar todos os vertices do grafo partindo de um vertice inicial.
// S� funciona para arestas ponderadas.
void dijkstra(int s)
{
    vector<int> Q; // Vetor utilizado no heap de minimo bin�rio
    
	// Inicializa��o
	p.resize(g.size(), -1);
	cor.resize(g.size(), false);
    d.resize(g.size(), INT_MAX);
	Q.push_back(s);
    d[s] = 0;
    cor[s] = true;
    
    // Enquanto o heap n�o estiver vazio
    while(!Q.empty()){
    	// Procedimento para retirar a raiz da estrutura de heap
        int u = Q[0];
        pop_heap(Q.begin(),Q.end(), comp);
		Q.pop_back();
        
        // Para todo vertice adjacente � "u"
        for(int i = 0; i < g[u].size(); i++) {
        	// Se o vertice adjacente � "u" for diferente do vertice pai de "u"
        	// E se a aresta para alcan�ar o vertice adjacente for mais leve do que a j� utilizada.
            if(d[u] + g[u][i].w < d[g[u][i].ind]){
                // Processo de relaxamento
				d[g[u][i].ind] = d[u] + g[u][i].w;
                p[g[u][i].ind] = u;
            }
            // Se o v�rtice adjacente ainda n�o foi encontrada.
            if(cor[g[u][i].ind] == false){
                cor[g[u][i].ind] = true; // Define o vertice adjacente como encontrado
                Q.push_back(g[u][i].ind); // Adiciona o vertice adjacente no heap
            }
        }
        make_heap(Q.begin(), Q.end(), comp); // Constroi o heap
    }
}

int main(){
	int n, m, k, a, b, A, posA, x, y, l;
	double p;
	bool aux;
	while(cin>>n>>m>>k>>p){
		g.resize(n+1);
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			g[a].push_back(Vertice(b,0));
			g[b].push_back(Vertice(a,0));
		}
		cin >> A;
		for(int i = 0; i < A; i++){
			cin >> posA;
			for(int j = 0; j < g[posA].size(); j++){
				l = 0;
				g[posA][j].w += 1;
				while(g[g[posA][j].ind][l].ind != posA){
					l++;
				}
				g[g[posA][j].ind][l].w += 1;
			}
		}
		cin >> x >> y;
		dijkstra(x);
		if(d[y] > k){
			cout <<"0.000"<< endl;
		}else{
			cout << fixed << setprecision(3) << pow(p,d[y]) << endl;
		}
		//cout << "d[y] -> "<< d[y] << endl;
		limpar();
	}
	return 0;
}
