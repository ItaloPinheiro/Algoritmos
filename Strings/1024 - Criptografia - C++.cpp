#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	string frase;
	cin >> n;
	getchar();//est� linha � para pegar o valor inserido de nfrases, se n�o o programa roda uma vez sem querer! 
	while(n--){
		//fase 1: Encripta��o com 3
		getline(cin,frase);
			for(int i = 0; i < frase.length(); i++){
				if((frase[i] >= 'A' && frase[i] <= 'Z') || (frase[i] >= 'a' && frase[i] <= 'z'))
					frase[i] += 3;
			}
			reverse(frase.begin(), frase.end());
			for(int i = frase.length() / 2; i < frase.length(); i++){
					frase[i] -= 1;
			}
	cout << frase << endl;
	}
	return 0;
} 	
