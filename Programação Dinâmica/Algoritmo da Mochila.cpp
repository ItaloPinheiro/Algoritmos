#include <iostream>
#include <stdio.h>
using namespace std;

int knapsack(int W, int* preco, int* peso, int n){
	// tabela de permissão que será preenchida
	int V[n + 1][W + 1], i, j;

	// inicializando a primeira linha e primeira coluna com 0
	for(j = 0; j <= W; j++)
		V[0][j] = 0;
	for(i = 1; i <= n; i++)
		V[i][0] = 0;

	for(i = 1; i <= n; i++){
		printf("passando o item -------> %d\n", i);
		for(j = 1; j <= W; j++){
			// elemento pode fazer parte da solução
			printf("peso do item -> %d / peso mochila rodando -> %d\n", peso[i-1], j);
			if(peso[i - 1] <= j){
				// max...
				printf("preco anterior -> %d / preco atual com o peso %d inserido -> %d\n", V[i - 1][j], peso[i - 1], preco[i - 1] + V[i - 1][j - peso[i - 1]]);
				V[i][j] = max(V[i - 1][j], preco[i - 1] + V[i - 1][j - peso[i - 1]]);
				
			}else{
				printf("peso %d nao colocado / preco anterior %d continua\n", peso[i - 1], V[i - 1][j]);
				V[i][j] = V[i - 1][j]; // não pode por na mochila o atual
			}
			puts("");
		}
		puts("*******************************************************************************");
	}	
	// retorna o valor máximo colocado na mochila
	return V[n][W];
}

int main(int argc, char *argv[]){
	// capacidade máxima da mochila: W
	int W = 20;

	// número de elementos
	int n = 5;

	// vetor com os valores (benefício) de cada elemento
	int preco[] = {3, 5, 8, 4, 10};

	// vetor com os pesos de cada elemento
	int peso[] = {2, 4, 5, 3, 9};

	// obtém o máximo valor que pode ser colocado na mochila
	int max_valor = knapsack(W, preco, peso, n);

	cout << "Valor maximo: " << max_valor << endl;

	return 0;
}
