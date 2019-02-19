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
		vector< vector<double> > dist;
		for(i = 0; i <= N+1; i++){
			dist.push_back(vector<double>(N+1, 0.0));	
		}	
		for(i = 0; i < M; i++){
			scanf("%d %d %lf", &v1, &v2, &p);
			dist[v1][v2] = dist[v2][v1] = 0.01 * p;
		}
		for(k = 1; k <= N; k++)
			for(i = 1; i <= N; i++){
				if(i == k) continue;
				for(j = 1; j <= N; j++){
					if(j == k || j == i) continue;
				//	printf("dist[%d][%d] = %lf\n", i, j, dist[i][j]);
				//	printf("dist[%d][%d] = %lf  OP  dist[%d][%d] = %lf ---> %lf\n", i, k, dist[i][k], k, j, dist[k][j], (dist[i][k] * dist[k][j]) / 100.000000); 
					if((dist[i][j] < dist[i][k] * dist[k][j]) && dist[i][k] && dist[k][j]){
						dist[i][j] = dist[i][k] * dist[k][j];
				//		printf("Alterado dist[%d][%d] = %lf\n", i, j, (dist[i][k] * dist[k][j]) / 100.000000);
					}
				//	puts("");
				}
			//	puts("============================================================");
			}
		printf("%.6lf percent\n", dist[1][N] * 100);
	}
}
