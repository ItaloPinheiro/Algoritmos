#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(){
	int nfrases, tam=0;
	char frase[100000], frase2[100000];
	char letra;
	cin >> nfrases;
	getchar();//está linha é para pegar o valor inserido de nfrases, se não o programa roda uma vez sem querer! 
	for(int num = 0; num < nfrases; num++){
		//fase 1: Encriptação com 3
		gets(frase);
			for(int i = 0; frase[i]; i++){
				letra = frase[i];
				if((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z')){
					letra += 3;
					frase[i] = letra;
				}
					frase[i] = letra;
			}
		//fase 2: Espelho
			strrev(frase);
		// fecha fase 2.
		//fase 3: Encriptação Metade pra frente
		tam = (int) strlen(frase) / 2;
		if(strlen(frase) % 2 != 0){
			tam -= 1;
		}
		
		for(int i = 0; frase[i]; i++){
				letra = frase[i];
				//algoritmo de decremento
				if(i >= tam+1){
					letra -= 1;
				}
				frase[i] = letra;
		}
	for(int i = 0; i < strlen(frase); i++){
		if(frase[i] >= 20){
			cout << frase[i];
		}
	}
	}
	return 0;
} 	
