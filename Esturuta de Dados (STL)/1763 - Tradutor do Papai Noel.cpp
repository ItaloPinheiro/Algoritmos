#include <iostream>
#include <map>

using namespace std;

int main(){
	map<string,string> M;
	map<string,string>::iterator it;
	M.insert(pair<string,string>("brasil","Feliz Natal!"));
	M.insert(pair<string,string>("alemanha","Frohliche Weihnachten!"));
	M.insert(pair<string,string>("austria","Frohe Weihnacht!"));
	M.insert(pair<string,string>("coreia","Chuk Sung Tan!"));
	M.insert(pair<string,string>("espanha","Feliz Navidad!"));
	M.insert(pair<string,string>("grecia","Kala Christougena!"));
	M.insert(pair<string,string>("estados-unidos","Merry Christmas!"));
	M.insert(pair<string,string>("inglaterra","Merry Christmas!"));
	M.insert(pair<string,string>("australia","Merry Christmas!"));
	M.insert(pair<string,string>("portugal","Feliz Natal!"));
	M.insert(pair<string,string>("suecia","God Jul!"));
	M.insert(pair<string,string>("turquia","Mutlu Noeller"));
	M.insert(pair<string,string>("argentina","Feliz Navidad!"));
	M.insert(pair<string,string>("chile","Feliz Navidad!"));
	M.insert(pair<string,string>("mexico","Feliz Navidad!"));
	M.insert(pair<string,string>("antardida","Merry Christmas!"));
	M.insert(pair<string,string>("canada","Merry Christmas!"));
	M.insert(pair<string,string>("irlanda","Nollaig Shona Dhuit!"));
	M.insert(pair<string,string>("belgica","Zalig Kerstfeest!"));
	M.insert(pair<string,string>("italia","Buon Natale!"));
	M.insert(pair<string,string>("libia","Buon Natale!"));
	M.insert(pair<string,string>("siria","Milad Mubarak!"));
	M.insert(pair<string,string>("marrocos","Milad Mubarak!"));
	M.insert(pair<string,string>("japao","Merii Kurisumasu!"));
	int aux;
	string nome;
	while(cin >> nome){
	aux = 0;
		for(it = M.begin(); it != M.end(); it++){
			if(it->first == nome){
				cout <<it->second<< endl;
				aux = 1;
				break;
			}
		}
		if(aux == 0)
		cout << "--- NOT FOUND ---" << endl;
	}
	return 0;
}
