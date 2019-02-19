#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int J, R, i, j, num;
	scanf("%d %d", &J, &R);
	int maior = 0, pos;
	int vet[J+1];
	for(i = 0; i < J; i++)
	    vet[i] = 0;
	    
	for(i = 0; i < R; i++){
		for(j = 0; j < J; j++){
			scanf("%d", &num);
			vet[j] += num;
			if(vet[j] >= maior){
				maior = vet[j];
			    pos = j+1;
			}
		}
	}
	printf("%d\n", pos);
	system("pause");
	return 0;
}
