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
    int V; // número de vértices

	// ponteiro para um array contendo as listas de adjacências
	list<pair<int, int> > * adj;
	
	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o número de vértices

		/*
			cria as listas onde cada lista é uma lista de pairs
			onde cada pair é formado pelo vértice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 à v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de distâncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
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
