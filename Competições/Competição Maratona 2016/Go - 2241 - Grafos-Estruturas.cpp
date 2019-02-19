#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(){
	
	int N, P;// tamanho da matriz e n de pedras
	int i, j, a, b, c; //variveis de controle
	int db, dp; //detectado branco ou preto
	int ap = 0, ab = 0; //area preta e area branca
	scanf("%d %d", &N, &P);
	int m[N+1][N+1];
    for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
		    m[i][j] = 0;
		
	for(i = 1; i <= P; i++){
		scanf("%d %d", &a, &b);
	    m[a][b] = 1;
	    ap++;
	}
	
	for(i = 1; i <= P; i++){
		scanf("%d %d", &a, &b);
	    m[a][b] = 2;
	    ab++;
	}
	int cont = 0;
	for(c = 2; c <= N; c++){
		for(i = 1; i <= N-c+1; i++){
			for(j = 1; j <= N-c+1; j++){
				db = 0; dp = 0;
				if(m[i][j] == 1 || m[i][j+1] == 1 || m[i+1][j] == 1 || m[i+1][j+1] == 1){
					dp = 1;
				}
				if(m[i][j] == 2 || m[i][j+1] == 2 || m[i+1][j] == 2 || m[i+1][j+1] == 2){
					db = 1;
				}
    			if((m[i][j] == 3 || m[i][j+1] == 3 || m[i+1][j] == 3 || m[i+1][j+1] == 3) ||
				(dp && db)){
					m[i][j] = 3;
					continue;
				}
				if(dp && !db){ ap++; m[i][j] = 1;}
				if(!dp && db){ ab++; m[i][j] = 2;}
				if(!dp && !db){ m[i][j] = 0;}
			}
		}
	}
	printf("%d %d\n", ap, ab);
	system("pause");
	return 0;
}
