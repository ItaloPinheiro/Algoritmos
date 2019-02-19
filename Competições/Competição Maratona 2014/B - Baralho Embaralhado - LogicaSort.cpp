#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int i, j, n, auxd, meio, pos, cont = 0;
	scanf("%d", &n);
	meio = (n/2);
	pos = meio + 1;
	for(i = 0; i < n; i++){
		if(pos <= meio){
            pos = pos*2;
		}
		else{
			auxd = pos - meio;
			pos = auxd*2 - 1;
		}
		cont++;
		//printf("pos -> %d/ auxd -> %d\n", pos, auxd);
		if(pos == meio + 1) break;
	}
	printf("%d\n", cont);
	system("pause");
}
