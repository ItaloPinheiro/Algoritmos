#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int nlinhas, nlinguas, aux=0;
	string lingua, lingua2;
	cin >> nlinhas;
	for(int i = 0; i < nlinhas; i++){
			cin >> nlinguas;
			cin >> lingua;
		for(int j = 1; j < nlinguas; j++){
			cin >> lingua2;
			if(lingua != lingua2){
				aux = 1; 
			}
		}
		if(aux)
			cout << "ingles" << endl;
		else
			cout << lingua << endl;
		
	aux = 0;
	}
	return 0;
}
