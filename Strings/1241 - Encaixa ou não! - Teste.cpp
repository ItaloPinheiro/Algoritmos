#include <iostream>
#include <string.h>
#include <stdio.h>


int main(){
  int n, i, j, aux;
    scanf("%d", &n);
    while(n--){
        char a[1000], b[1000];
        scanf("%s %s", a, b);
       	for(int i = strlen(b), j = strlen(a); i >= 0; i--, j--){
       	if(a[j] == b[i]) aux = 1;	
		else aux = 0;
		}
        printf("%s\n", aux == 0 ? "nao encaixa" : "encaixa");
	}
	return 0;
}
