#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int nlinhas, j=0;
	string nome, linhas;
	cin >> nlinhas;
	int numf[nlinhas];
	getline(cin, linhas);
	for(int i = 0; i < nlinhas; i++){
		getline(cin,nome);
			if(nome.length() == 3){
				if((nome.at(j) == 'o' && nome.at(j+1) == 'n') || 
				   (nome.at(j) == 'o' && nome.at(j+2) == 'e') ||
				   (nome.at(j+1) == 'n' && nome.at(j+2) == 'e'))
					numf[i] = 1;
				else
					numf[i] = 2;
			}
			if(nome.length() == 5)
					numf[i] = 3;
	}
	for(int i = 0; i < nlinhas; i++){
		cout << numf[i] << endl;
	}
	return 0;
}

