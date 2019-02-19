#include <iostream>
#include <list>

using namespace std;

int main(){
	int contc, aux;
	float valor;
	string comp;
	cin >> comp;
	while(comp != "*"){
		aux = 0; valor = 0.0; contc = 0;
		list<char> ci;
		list<char>::iterator it;
		for(int i = 0; comp[i]; i++){
			ci.push_back(comp[i]);
		}
		for(it=ci.begin(); it != ci.end(); it++){
			if(aux==0){
			it++; aux = 1;}
			while(*it != '/'){
				switch(*it){
					case 'W': valor += 1; break;
					case 'H': valor += 0.5; break;
					case 'Q': valor += 0.25; break;
					case 'E': valor += 0.125; break;
					case 'S': valor += 0.0625; break;
					case 'T': valor += 0.03125; break;
					case 'X': valor += 0.015625;
				}
			it++;
			}
			if(valor == 1.00){
				contc++;
			}
		valor = 0.0;
		}
	cout << contc << endl;
	cin >> comp;
	}
	return 0;
}
