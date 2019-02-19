#include <iostream>
#include <string.h>
#include <stdio.h>

int main(){
  int n, i, j, aux;
    scanf("%d", &n);
    while(n--){
    	aux = 0;
        char a[1000], b[1000];
        scanf("%s %s", a, b);
       	for(int i = strlen(b) - 1, j = strlen(a) - 1; i >= 0; i--, j--){
       	if(a[j] == b[i]  && i <= j) aux = 1;	
		else {aux = 0; break;}
		}
        printf("%s\n", aux ? "encaixa" : "nao encaixa");
	}
	return 0;
}
