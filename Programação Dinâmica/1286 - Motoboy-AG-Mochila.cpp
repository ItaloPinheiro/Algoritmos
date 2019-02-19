#include <iostream>
#include <stdio.h>
using namespace std;

int knapsack(int W, int* tempo, int* pizza, int n){
	int V[n + 1][W + 1], i, j;
	
	for(j = 0; j <= W; j++) V[0][j] = 0;
	for(i = 1; i <= n; i++) V[i][0] = 0;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= W; j++)
			if(pizza[i - 1] <= j)
				V[i][j] = max(V[i - 1][j], tempo[i - 1] + V[i - 1][j - pizza[i - 1]]);	
			else
				V[i][j] = V[i - 1][j];
				
	return V[n][W];
}

int main(int argc, char *argv[]){
	int n, W;
	while(scanf("%d", &n) && n != 0){
		scanf("%d", &W);
		int tempo[n], pizza[n];
		for(int i = 0; i < n; i++)	cin >> tempo[i] >> pizza[i];
		int max_valor = knapsack(W, tempo, pizza, n);
		cout << max_valor << " min." << endl;
	}
	return 0;
}
