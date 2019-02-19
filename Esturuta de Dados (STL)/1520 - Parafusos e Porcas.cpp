#include <iostream>
#include <set>

using namespace std;

int main(){
	int n, num, ini, fim, j, posini, posfim, aux, aux1;
	while(cin >> n){
		multiset<int> ci;
		multiset<int>::iterator it;
		while(n--){
			j=0, posini=0, posfim=0, aux=0, aux1=0;
			cin >> ini >> fim;
			for(int i = ini; i <= fim; i++){
				ci.insert(i);
			}
		}
		cin >> num;
		for(it = ci.begin(); it != ci.end(); it++, j++){
	    	if(*it == num){
	    	posini = j; aux = 1;
			break;
	    	}	
		}
		for(it = ci.end(), j = ci.size(); it != ci.begin(); it--, j--){
	    	if(*it == num){
	    	posfim = j; aux1 = 1;
			break;
	    	}	
		}
		if(aux == 0 && aux1 == 0)
			cout << num << " not found" << endl;
		else
			cout << num << " found from " << posini << " to " << posfim << endl; 
	}
	
	
	
	return 0;
}
