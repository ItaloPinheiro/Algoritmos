#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int nlinhas, numled=0;
	string num, linhas;
	char letra;
	cin >> nlinhas;
	int totled[nlinhas];
	getline(cin,linhas);
	for(int i = 0; i < nlinhas; i++){
		getline(cin,num);
		for(int j = 0; j < num.length(); j++){
			letra = num.at(j);
			if (letra == '1')
				numled += 2;
			if (letra == '2' || letra == '3' || letra == '5')
				numled += 5;
			if (letra == '4')
				numled += 4;
			if (letra == '6' || letra == '9' || letra == '0')
				numled += 6;
			if (letra == '7')
				numled += 3;
			if (letra == '8')
				numled += 7;
		}
	totled[i] = numled;
	numled = 0;
	}
	for(int i = 0; i < nlinhas; i++){
		cout << totled[i] << " leds" << endl;
	}
	return 0;
}
