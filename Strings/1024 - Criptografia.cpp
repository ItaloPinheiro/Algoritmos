#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int nfrases, numletra=0, tam=0;
	string frase, frase2="", frase3="", frasef, Nnfrases;
	char letra, teste;
	cin >> nfrases;
	getline(cin,Nnfrases);//está linha é para pegar o valor inserido de nfrases,
	string frasesf[nfrases];  // se não o programa roda uma vez sem querer! 
	for(int num = 0; num < nfrases; num++){
		//fase 1: Encriptação com 3
		getline(cin,frase);
			for(int i = 0; i < frase.length(); i++){
				letra = frase.at(i);
				numletra = letra;
				if(numletra > 64)
					numletra += 3;
					
					letra = numletra;
					frase2 += letra;
			numletra=0;
			}
		//fase 2: Espelho
		for(int i = frase2.length(); i >= 0; i--){
		 letra = frase2[i-1];
		 frase3 += letra;
		}
		// fecha fase 2.
		//fase 3: Encriptação Metade pra frente
		tam = (int) frase3.length() / 2;
		if(frase.length() % 2 != 0){
			tam -= 1;
		}
		
		for(int i = 0; i < frase3.length(); i++){
				letra = frase3.at(i);
				numletra = letra;
				//algoritmo de decremento
				if(i >= tam){
					numletra -= 1;
				}
				//Algoritmo - apagar carac inválido
				if(numletra <= 31){
					frase3.erase(i,0);
				}else{
					letra = numletra;
					frasef += letra;
				}
				//fecha carac inválido
		}
		// fecha fase 3.
		//Guardando no vetor e finalizando
	frasesf[num] = frasef;
	frase = ""; frase2 = ""; frase3 = ""; frasef = "";
	numletra = 0; tam = 0;
	}
	for(int i = 0; i < nfrases; i++){
		cout << frasesf[i] << endl;
	}
	return 0;
}
