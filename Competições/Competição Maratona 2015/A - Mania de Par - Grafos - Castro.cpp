#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:


public:
    int V; // n�mero de v�rtices

	// ponteiro para um array contendo as listas de adjac�ncias
	list<pair<int, int> > * adj;
	
	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o n�mero de v�rtices

		/*
			cria as listas onde cada lista � uma lista de pairs
			onde cada pair � formado pelo v�rtice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 � v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de dist�ncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o v�rtice j� tenha sido
		   expandido (visitado), n�o expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, v�rtice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de dist�ncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a dist�ncia de orig para orig � 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obt�m o v�rtice do pair
			pq.pop(); // remove da fila

			// verifica se o v�rtice n�o foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os v�rtices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obt�m o v�rtice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a dist�ncia de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a dist�ncia m�nima at� o destino
		return dist[dest];
	}
};

int main(){
	int a, b, n, m, p, i, j, k;
	scanf("%d %d", &n, &m);
	Grafo gaux(n+1);
	Grafo g(n+1);
	for(i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &p);
	    gaux.addAresta(a, b, p);
		gaux.addAresta(b, a, p);
	}
	for(i = 1; i < n; i++){
        //printf("teste - %d\n", gaux[i].size());
		for(j = 0; j < gaux.adj[i].end(); j++){
            //printf("teste - %d\n", gaux[gaux[i][j].ind].size());
			for(k = 0; k < gaux.adj[].size(); k++){
				//printf("%d -> %d -> %d / pesos: %d e %d\n", i, gaux[i][j].ind, gaux[gaux[i][j].ind][k].ind,
				//gaux[i][j].w, gaux[gaux[i][j].ind][k].w);
				//system("pause");
				g[i].push_back(Vertice(gaux[gaux[i][j].ind][k].ind, gaux[i][j].w +  gaux[gaux[i][j].ind][k].w));
				//g[gaux[gaux[i][j].ind][k].ind].push_back(Vertice(i, gaux[i][j].w +  gaux[gaux[i][j].ind][k].w));
			}
		}
	}

	dijkstra(1);
	limpar();
	system("pause");
	return 0;
}
