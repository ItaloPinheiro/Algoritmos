#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(){
	int i, j, k;
	int N, M, v1, v2;
	double p;
	while(scanf("%d", &N) && N){
		scanf("%d", &M);
		vector< vector<int> > dist;
		for(i = 0; i <= N+1; i++){
			dist.push_back(vector<int>(N+1, 0);	
		}	
		for(i = 0; i < M; i++){
			scanf("%d %d %lf", &v1, &v2, &p);
			dist[v1][v2] = dist[v2][v1] = p;
		}
		for(k = 1; k <= N; k++)
			for(i = 1; i <= N; i++){
				if(i == k) continue; //especifico do problema
				for(j = 1; j <= N; j++){
					if(j == k || j == i) continue; //especifico do problema
					if(dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				//		printf("Alterado dist[%d][%d] = %lf\n", i, j, (dist[i][k] * dist[k][j]) / 100.000000);
					}
				//	puts("");
				}
			//	puts("============================================================");
			}
		printf("%d", dist[1][N]);
	}
}
