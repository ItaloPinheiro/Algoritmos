#include <iostream>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main(){
	int n, cont, nnotas, nota;
	cin>>n;
	while(n--){
		cont = 0;
		multiset<int> ci;
		multiset<int>::iterator it;
		list<int> cii;
		list<int>::iterator iti;
		cin >> nnotas;
		for(int i = 0; i < nnotas; i++){
			cin >> nota;
			ci.insert(nota);
			cii.push_back(nota);
		}
		reverse(cii.begin(), cii.end());
		for(it = ci.begin(), iti = cii.begin(); 
			it != ci.end() && iti != cii.end();
			it++, iti++)
			if(*it == *iti)
			cont++;
	cout << cont << endl;
	}
	return 0;
}

 
