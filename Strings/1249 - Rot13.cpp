#include <iostream>

using namespace std;

int main(){
	string frase;
	while(getline(cin,frase)){
		for(int i = 0; frase[i]; i++){
			if(frase[i] >= 'a' && frase[i] <= 'z'){
				if(frase[i] >= 'n')
					frase[i] = 'a' + (12 - ('z' - frase[i]));
				else
					frase[i] += 13;
			} 
			else if(frase[i] >= 'A' && frase[i] <= 'Z'){
				if(frase[i] >= 'N')
					frase[i] = 'A' + (12 - ('Z' - frase[i]));
				else
					frase[i] += 13;
			}
		}
	cout << frase << endl;
	}
	return 0;
}
