#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	int i, j, n, c;
	scanf("%d %d", &n, &c);
	int acao[n+1];
	int lucro[n+1];
	for(i = 0; i < n; i++)
	    scanf("%d", acao+i);
	lucro[0] = 0;
	for(i = 1; i < n; i++){
		lucro[i] = lucro[i-1];
		printf("lucro entrou com -> %d\n", lucro[i]);
		puts("________________________________________");
		for(j = 0; j < i; j++){
			lucro[i] = max(lucro[i], acao[i] - acao[j] - c + lucro[j]);
			printf("lucro rodando com -> %d\n", lucro[i]);
		}
		puts("________________________________________");
		printf("lucro max local -> %d\n", lucro[i]);
		puts("");
	}
	printf("%d\n", lucro[n-1]);
	system("pause");
	return 0;
}
