#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int x, y, aux = 0, cont = 0;
	scanf("%d %d", &x, &y);
	while(aux < y){
		cont++;
		aux += y-x;
	}
	printf("%d\n", cont);
	system("pause");
}
