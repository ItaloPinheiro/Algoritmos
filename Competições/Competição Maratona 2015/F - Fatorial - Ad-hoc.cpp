#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int fat[n+1], i, aux, cont = 0;
	fat[1] = 1;
	i = 1;
	while(fat[i] < n){
		fat[++i] = fat[i-1] * i;
	}
	aux = i-1;
	while(n > 0){
		n -= fat[aux];
		//printf("n -> %d\n", n);
		cont++;
		while(fat[aux] > n){
			aux--;
		}
	}
	printf("%d\n", cont);
	system("pause");
	return 0;
}
