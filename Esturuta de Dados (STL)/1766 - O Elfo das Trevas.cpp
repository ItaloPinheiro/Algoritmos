#include <iostream>
#include <set>
using namespace std;

int main(){
	int t, i;
	cin >> t;
	int cont = 1;
	while(t--){
	multiset< pair< int, pair< int, pair< float, string> > > > ci;
	multiset< pair< int, pair< int, pair< float, string> > > >::iterator it;
	int totrenas, totsolic;
	cin >> totrenas >> totsolic;
		while(totrenas--){
		float altura;
		int peso, idade;
		string nome;
		cin >> nome >> peso >> idade >> altura;
		ci.insert(make_pair (peso*(-1), make_pair (idade, make_pair(altura, nome))));
		//peso*(-1) pois queremos que a ordenção por peso seja decrescente;
		}
		cout << "CENARIO {" << cont << "}" << endl;
		for(i = 1, it = ci.begin(); i <= totsolic; i++, it++){
		cout << i << " - " << it->second.second.second << endl;
		}
	cont++;
	}
	return 0;
}
