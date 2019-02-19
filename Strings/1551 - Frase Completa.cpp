#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n, numletra, soma;
	string frase;
	cin >> n;
	getchar();
	while(n--){
		getline(cin,frase);
		int letra[123];
		for(int i = 97; i < 123; i++){
			letra[i] = 0;
		}
		for(int i = 0; frase[i]; i++){
			frase[i] = tolower(frase[i]);
		}
		for(int i = 0; frase[i]; i++){
			if(frase[i] <= 'z' && frase[i] >= 'a'){
			numletra = frase[i];
			letra[numletra] = 1;
			}
		}
		for(int i = 97; i < 123; i++){
			soma += letra[i];
		}
		cout << soma << endl;
		if (soma == 26)
			cout << "frase completa" << endl;
		else if(soma < 26 && soma >= 13)
			cout << "frase quase completa" << endl;
		else
			cout << "frase mal elaborada" << endl;
	soma = 0; numletra = 0;
	}
	return 0;
}
