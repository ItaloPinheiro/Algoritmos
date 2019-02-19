#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int n, i, maior = 0;
	scanf("%d", &n);
	int h[n+1], esq[n+1], dir[n+1];
	for(i = 1; i <= n; i++){
		scanf("%d", &h[i]);
	}
	esq[1] = 1;
	dir[n] = 1;

	for(i = 1; i < n; i++){
		esq[i+1] = min(esq[i] + 1, h[i+1]);
	}

	for(i = n; i > 1; i--){
		dir[i-1] = min(dir[i] + 1, h[i-1]);
	}

	for(i = 1; i <= n; i++){
		h[i] = min(esq[i], dir[i]);
		if(h[i] > maior) maior = h[i];
	}
	printf("%d\n", maior);
	system("pause");

}

