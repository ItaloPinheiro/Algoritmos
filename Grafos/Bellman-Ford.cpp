#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#define MAX INT_MAX
using namespace std;

int main(){
	int i, j, k;
	int N, M, v1, v2;
	int source, p;
	int *predecessor;
	while(scanf("%d", &N) && N){ // Numero de vertices
		scanf("%d", &M); // numero de arestas
		scanf("%d", &source); // vertice inicial
		vector<int> dist(N+1, MAX);
		list< pair< pair<int, int>, int > > g;
		list< pair< pair<int, int>, int > >::iterator it;
		
		predecessor = new int[M+1];
		for(i = 0; i < M; i++){
			scanf("%d %d %d", &v1, &v2, &p);
			g.push_back(make_pair(make_pair(v1, v2), p)); // directed graph
			predecessor[i] = 0;
		}
		
		dist[source] = 0;
		for(k = 0; k < N-1; k++){
			for(it = g.begin(); it != g.end(); it++){
				v1 = it->first.first; v2 = it->first.second;
			//	printf("aresta: %d - %d -> %d\n", v1, v2, it->second);
			//	printf("pesos: dist[v1] = %d / dist[v2] = %d / peso: %d\n", dist[v1], dist[v2], it->second);
				dist[v2] = min(dist[v1] + it->second, dist[v2]);
			//	printf("dist novo = %d\n", dist[v2]);
				predecessor[v2] = v1;
			//	puts("");
			}
		//	printf("--------------------------------------\n");
		}
		
		for(i = 1; i <= N; i++){
			printf("%d -> %d\n", i, dist[i]);
		}
	}
}
