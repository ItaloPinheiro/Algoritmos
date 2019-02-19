#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int n;
	string a, b;
	cin >> n;
	for(int i = 0; i < n; i++){
	cin >> a >> b;
		if((a == "tesoura" && (b == "papel" || b == "lagarto")) ||
		(a == "papel" && (b == "pedra" || b == "spock")) ||
		(a == "lagarto" && (b == "papel" || b == "spock")) ||
		(a == "spock" && (b == "pedra" || b == "tesoura")) ||
		(a == "pedra" && (b == "lagarto" || b == "tesoura"))){
			cout << "rajesh"<< endl;
		}
		else if((b == "tesoura" && (a == "papel" || a == "lagarto")) ||
		(b == "papel" && (a == "pedra" || a == "spock")) ||
		(b == "lagarto" && (a == "papel" || a == "spock")) ||
		(b == "spock" && (a == "pedra" || a == "tesoura")) ||	
		(b == "pedra" && (a == "lagarto" || a == "tesoura"))){
			cout << "sheldon" << endl;
		}
		else
			cout << "empate" << endl;	
	}
	return 0;
}
