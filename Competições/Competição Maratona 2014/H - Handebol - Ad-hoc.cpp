#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
	int m, n, num, cont, res = 0;
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; i++){
        cont = 0;
		for(int j = 0; j < n; j++){
			scanf("%d", &num);
			if(num) cont++;
		}
		if(cont == n) res++;
	}
	printf("%d\n", res);
	system("pause");
}
