#include <iostream>
#include <stdio.h>
#include <string.h>

int main(){
	int aux=0;
	char carac[100];
		while( gets(carac) != NULL){
			for(int i = 0; carac[i]; i++){ // quando chegar no \0 para!
				if(carac[i] != ' '){
					if(aux){
						carac[i] = tolower(carac[i]); aux = 0;
					}else{
						carac[i] = toupper(carac[i]); aux = 1;
					}
				}
			}
		aux = 0;
		puts(carac);
		}
	return 0;
}
