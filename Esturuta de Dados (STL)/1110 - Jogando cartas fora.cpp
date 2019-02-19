#include <iostream>
#include <list>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		int descarte[51];
		list<int> lista;
		list<int>::iterator it;
		for(int i = n; i >= 1; i--)
			lista.push_back(i);
		
		for(int j = 0; lista.size() >= 2; j++){
			if(lista.size() > 1){
				descarte[j] = lista.back();
				lista.pop_back();
			}
			lista.push_front(lista.back());
			lista.pop_back();
		}
		cout << "Discarded cards: " << descarte[0];
		for(int i = 1; i < n-1; i++)
			cout <<", " <<descarte[i];
		
	cout << "\nRemaining card: " << lista.front() << endl;
	cin >> n;
	}
	return 0;
}
