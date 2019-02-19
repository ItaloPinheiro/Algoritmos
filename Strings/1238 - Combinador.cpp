#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string f1, f2;
		int menor, aux=0;
		cin >> f1 >> f2;
		if(f1.length() < f2.length()){
			menor = f1.length(); aux = 1;
		}
		else{
			menor = f2.length();
		}
		for(int i = 0; i < menor; i++){
			cout << f1[i] << f2[i];
		}
		if(aux)
			for(int i = f1.length(); i < f2.length(); i++)
			cout << f2[i];
		else
			for(int i = f2.length(); i < f1.length(); i++)
			cout << f1[i];
		
	cout << endl;
	}
	return 0;
}
