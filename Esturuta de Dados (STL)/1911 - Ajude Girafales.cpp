#include <iostream>
#include <map>
using namespace std;

int main(){
	int alunos, consulta, erro, trapaca;
	string nome, ass, getass;
	cin >> alunos;
	while(alunos){
		trapaca = 0; erro = 0;
		map<string, string> mapa;
		map<string, string>::iterator it;
		for(int i = 0; i < alunos; i++){
			cin >> nome >> ass;
			mapa.insert(pair<string, string>(nome, ass));
		}
		cin >> consulta;
		for(int i = 0; i < consulta; i++){
			cin >> nome >> ass;
			it = mapa.find(nome);
			getass = it->second;
			for(int i = 0; getass[i]; i++){
				if(getass[i] != ass[i]){
					erro++;
					if(erro >= 2){
						trapaca++; erro = 0;
						break;
					}
				}
			}
		erro = 0;
		}
	cout << trapaca << endl;
	cin >> alunos;
	}
	return 0;
}
