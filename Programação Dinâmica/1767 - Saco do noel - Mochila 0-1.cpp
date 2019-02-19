#include <iostream>
#include <stdio.h>
using namespace std;

void knapsack(int W, int* qtd, int* peso, int n){
	int V[n + 1][W + 1], i, j, sobra = n, w = 0;
	
	for(j = 0; j <= W; j++) V[0][j] = 0;
	for(i = 1; i <= n; i++) V[i][0] = 0;

	for(i = 1; i <= n; i++){
		for(j = 1; j <= W; j++){
			if(peso[i - 1] <= j){
				V[i][j] = max(V[i - 1][j], qtd[i - 1] + V[i - 1][j - peso[i - 1]]);
				//printf("%d ", V[i][j]);
			}else{
				V[i][j] = V[i - 1][j];
				//printf("%d ", V[i][j]);
			}
		}
		//puts("");
	}
	/*
	puts("---------------------------------------");
	for(i = 0; i <= n; i++){
		for(j = 0; j <= W; j++)
			printf("%d ", V[i][j]);
		puts("");
	}*/
	// nessa parte do código é possivel resgatar via top-down os pesos usados na solução
	// e também quantos dos iniciais não foram usados
	j = W;
	for(i = n; i > 0; i--){
		if(V[i-1][j] != V[i][j]){
			w += peso[i-1];
			j -= peso[i-1];
			sobra--;
		}
	}
	
	printf("%d brinquedos\n", V[n][W]);
	printf("Peso: %d kg\n", w);
	printf("sobra(m) %d pacote(s)\n\n", sobra);
}

int main(int argc, char *argv[]){
	int cases, n, W = 50;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &n);
		int qtd[n], peso[n];
		for(int i = 0; i < n; i++) cin >> qtd[i] >> peso[i];
		knapsack(W, qtd, peso, n);
	}
	return 0;
}
