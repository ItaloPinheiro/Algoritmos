#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int numl, n, maior[27], max, qtdl[123];
	string frase, letra;
	cin >> n;
	getchar();
	for(int k = 0; k < n; k++){
		getline(cin,frase);
		letra=""; max=0; numl=0;
		for(int i = 0; i < 123; i++){
			qtdl[i] = 0;
			if(i <= 26)
			maior[i] = 0;
		}
		for(int i = 0; i < frase.length(); i++){
			if(frase[i] >= 'A' && frase[i] <= 'Z' )
				frase[i] = tolower(frase[i]);
			if(frase[i] >= 'a' && frase[i] <= 'z'){
			numl = frase[i];
			qtdl[numl]++;
			}
		}
		for(int i = 97, j = 0; i < 123; i++){
			if(qtdl[i] >= max){
			max = qtdl[i];
			maior[j] = qtdl[i];
			}
			j++;
		}

		for(int i = 0, j = 97; i < 27; i++){
			if(maior[i] >= max){
			letra = j;
			cout << letra;
			}
			j++;
		}
		cout << endl;
	}
	return 0;
}
