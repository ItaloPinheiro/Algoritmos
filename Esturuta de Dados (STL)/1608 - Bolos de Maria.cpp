#include <iostream>
#include <map>
using namespace std;

int main(){
	int casos, din, qtding, bolos;
	int precoi, qibusca, indiceing, multi;
	int porbolo, parcialbolo, qtdbolo;
	cin >> casos;
	while(casos--){
		porbolo = 0; parcialbolo = 0; qtdbolo = 0;
		map<int,int> ip;
		map<int,int> it_ip;
		cin >> din >> qtding >> bolos;
		for(int i = 0; i < qtding; i++){
			cin >> precoi;
			ip.insert(pair<int,int>(i,precoi));
		}
		for(int i = 0; i < bolos; i++){
			cin >> qibusca;
			for(int j = 0; j < qibusca; j++){
				cin >> indiceing >> multi;
				precoi = multi * (ip.find(indiceing)->second);
				porbolo += precoi;
			}
			parcialbolo = din/porbolo;
			if(qtdbolo < parcialbolo){
				qtdbolo = parcialbolo;
			}
		porbolo = 0; parcialbolo = 0;
		}
	cout << qtdbolo << endl;
	}
	return 0;
}
