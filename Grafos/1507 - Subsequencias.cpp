#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		string str1, str2, consulta;
		cin >> str1;
		int nconsulta;
		cin >> nconsulta;
		while(nconsulta--){
			int posL, posLA = 0, aux = 1;
			str2 = str1;
			cin >> consulta;
			for(int i = 0; i < consulta.length(); i++){
				posL = str2.find_first_of(consulta[i], posLA);
				//cout << "STR2: " << str2 << "/ ";
				//cout << consulta[i] << " - " << posL << endl << endl;
				str2[posL] = '#';
				if(posL < posLA){
				cout << "No" << endl;
				aux = 0; break;
				}
				posLA = posL;
			}
			if(aux) cout << "Yes" << endl;
		}
	}
system("PAUSE");
return 0;
}
