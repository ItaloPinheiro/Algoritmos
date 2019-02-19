#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string frase;
	while(getline(cin,frase)){
		int aux = 0, aux1 = 0;
		for(int i = 0; i < frase.length(); i++){
			if(frase[i] == '_' && !aux){
				frase.erase(i,1);
				frase.insert(i,"<i>");
				aux = 1;
			}
			if(frase[i] == '_' && aux){
				frase.erase(i,1);
				frase.insert(i,"</i>");
				aux = 0;
			}
			if(frase[i] == '*' && !aux1){
				frase.erase(i,1);
				frase.insert(i,"<b>");
				aux1 = 1;
			}
			if(frase[i] == '*' && aux1){
				frase.erase(i,1);
				frase.insert(i,"</b>");
				aux1 = 0;
			}
		}
		cout << frase << endl;
	}
	return 0;
}
