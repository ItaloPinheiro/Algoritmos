#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n, cont=0, aux=0, sn=0; // sn = condicional letra igual a temp
	char letra1, letra2, temp; // aux = condicional letra1 ou letra2;
	string frase;
	memset(&letra1, 0, sizeof (letra1));
	memset(&letra2, 0, sizeof (letra2));
	memset(&temp, 0, sizeof (temp));		  
	while(getline(cin,frase) != NULL){
	    for(int i = 0; i < frase.length(); i++){
	    	frase[i] = tolower(frase[i]);
		}
		for(int i = 0; i < frase.length(); i++){
			if(i == 0 && frase[i] >= 'a' && frase[i] <= 'z'){
				letra1 = frase[i];
				temp = letra1;
				aux = 1;
			}
	    	else if(frase[i] >= 'a' && frase[i] <= 'z' && frase[i - 1] == ' '){
	    		if(aux == 0){
	    		letra1 = frase[i];
	    		temp = letra1; 
				aux = 1;
	    		}else{
	    		letra2 = frase[i];
	    		aux = 0; sn = 0;
	    		}
			}
			if(aux == 1 && temp == letra1 && letra1 == letra2 && sn == 1){
				aux = 0; sn = 1;
			}else{
				if(letra1 == letra2 && sn == 0){
				cont++; sn = 1;
				}
			}	
		}
		cout << cont << endl;
		aux = 0; cont = 0;
		memset(&letra1, 0, sizeof (letra1));
		memset(&letra2, 0, sizeof (letra2));
		memset(&temp, 0, sizeof (temp));
	}
	return 0;
}
