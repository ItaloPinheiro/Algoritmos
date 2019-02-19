#include <iostream>
#include <stdio.h>
using namespace std;

int knapsack(int W, int* damage, int* wt, int n){
	int V[n + 1][W + 1], i, j;
	
	for(j = 0; j <= W; j++) V[0][j] = 0;
	for(i = 1; i <= n; i++) V[i][0] = 0;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= W; j++)
			if(wt[i - 1] <= j)
				V[i][j] = max(V[i - 1][j], damage[i - 1] + V[i - 1][j - wt[i - 1]]);	
			else
				V[i][j] = V[i - 1][j];
				
	return V[n][W];
}

int main(int argc, char *argv[]){
	int c, n, W, R;
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);
		int damage[n], wt[n];
		for(int i = 0; i < n; i++)	cin >> damage[i] >> wt[i];
		scanf("%d%d", &W, &R);
		int max_valor = knapsack(W, damage, wt, n);
		if(max_valor >= R) puts("Missao completada com sucesso");
		else puts("Falha na missao");
	}
	return 0;
}
