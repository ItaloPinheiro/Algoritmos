#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<climits>

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
                cor[g[u][i].ind] = true; 
				Q.push_back(g[u][i].ind);
            }
        }
        make_heap(Q.begin(), Q.end(), comp); // Constroi o heap
    }
}

int main(){
	int n, m, a, b, p, casos, j;
	bool aux;
	while(cin>>n>>m && n != 0){
		g.resize(n+1);
		for(int i = 0; i < m; i++){
			cin >> a >> b >> p;
			aux = false;
			for(j = 0; j < g[b].size(); j++){
				if(g[b][j].ind == a){
					aux = true;
					break;
				}
			}
			if(aux){ g[a].push_back(Vertice(b,0)); g[b][j].w = 0.00;
			}else g[a].push_back(Vertice(b,p));
		}
		cin >> casos;
		while(casos--){
			cin >> a >> b;
			dijkstra(a);
			if(d[b] >= 0 && d[b] <= 1000) cout << d[b] << endl;
			else cout << "Nao e possivel entregar a carta" << endl;
			cor.clear();
			d.clear();
		}
	limpar();
	cout << endl;
	}
	return 0;
}
