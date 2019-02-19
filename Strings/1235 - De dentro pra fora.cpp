#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string frase;
	int n;
	cin >> n;
	getchar();
	while(n--){
		string parte1="", parte2="";
		int nparte1=0, nparte2=0;
		getline(cin,frase);
		if(frase.length() % 2 == 0){
			nparte1 = frase.length() / 2;
			nparte2 = nparte1;
		}else{
			nparte1 = frase.length() / 2;
			nparte2 = nparte1; 
		}
		for(int i = nparte1 - 1; i >= 0; i--){
			parte1 += frase[i];
		} 
		for(int i = frase.length() - 1; i >= nparte2; i--){
			parte2 += frase[i];
		}
		cout << parte1 << parte2 << endl;
	}
	return 0;
}
