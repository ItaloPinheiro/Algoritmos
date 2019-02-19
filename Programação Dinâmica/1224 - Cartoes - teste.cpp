#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int card(int* v, int* r, int St, int i, int j){
	if(i == j){
		printf("Retornando o valor: %d\n", v[i]);
		printf("com i: St -> %d / v[%d] -> %d / i -> %d / j -> %d\n", St, i, v[i], i, j);
		printf("com j: St -> %d / v[%d] -> %d / i -> %d / j -> %d\n", St, j, v[j], i, j);
		puts("");
		return v[i];
	}
	else{
		int v1, v2;
		printf("com i: St -> %d / v[%d] -> %d / i -> %d / j -> %d\n", St, i, v[i], i, j);
		printf("com j: St -> %d / v[%d] -> %d / i -> %d / j -> %d\n", St, j, v[j], i, j);
		v1 = card(v, r, St - v[j], i, j - 1);
		v2 = card(v, r, St - v[i], i + 1, j);
		r[j-i] = St - min(v1, v2);
		printf("St -> %d / v1 -> %d / v2 -> %d\n", St, v1, v2);
		printf("Retornou -> %d\n", r[j-i]);
		return r[j-i];
	}
	
}


int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int v[n+1], r[n+1], aux[n+1], i, St = 0;
		for(i = 0; i < n; i++){
			scanf("%d", v+i);
			St += v[i];
		}
		St = card(v, r, St, 0, n - 1);
		printf("%d\n", St);
	}
	return 0;
}
