#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char d;
	string n;
	cin >> d;
	while(d != '0'){
		int aux = 0;
		cin >> n;
		for(int i = 0; i < n.length(); i++){
			if(n[i] == d)
			n.erase(i,0);
		}
		for(int i = 0; n[i]; i++){
			if(n[i] != '0'){
			aux = 1; break;
			}
		}
		if(n == "")
			cout << 1 << endl;
		else{
			if(aux)
			cout << n << endl;
			else
			cout << 0 << endl; 
		}
		cin >> d;
	}
	return 0;
}
