#include <iostream>
#include <set>
#include <list>

using namespace std;

int main(){
	int n, cont, j, aux;
	string num, numcomp;
	while(cin >> n){
		aux = 0; cont = 0;
		multiset<string> sci;
		multiset<string>::iterator siti;
		for(int i = 0; i < n; i++){
			cin >> num;
			sci.insert(num);
		}
		siti = sci.begin();
		num = *siti;
		for(siti = sci.begin(); siti != sci.end(); siti++){
			if(!aux){
			siti++; aux = 1;}
			numcomp = *siti;
			list<char> ci;
			list<char>::iterator iti;
			for(int i = 0; num[i]; i++)
				ci.push_back(num[i]);
		
				for(iti = ci.begin(), j = 0; iti != ci.end(); iti++, j++)
					if(*iti == numcomp[j])
					cont++;
					else break;
				num = *siti;	
		}
		cout << cont << endl;	
	}
	return 0;
}
