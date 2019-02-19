#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int i, j, ciclo, aux, p;
	string frase;
	while(cin >> frase){
		cin >> p;
		i = 0; ciclo = 0;
		while(frase[i]) 
			for(aux = 0, j = 0; frase[i] && j < p; i++, j++)
				if(frase[i] == 'W'){
					ciclo++; j = p;
				}
				else if(frase[i] == 'R' && !aux){
					ciclo++; aux = 1;
				}
		
		cout << ciclo << endl;
	}
	return 0;
}
