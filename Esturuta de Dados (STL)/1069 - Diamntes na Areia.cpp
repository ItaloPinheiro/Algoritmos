#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n, cont;
	string v;
	cin >> n;
	while(n--){
		cin >> v;
		stack<char> ci;
		for(int i = 0; v[i]; i++){
			if(v[i] == '<')
				ci.push(v[i]); 
			
			if(v[i] == '>')
				if(ci.size()){
				ci.pop(); cont++;
				}
		}
		cout << cont << endl; cont = 0;
	}
	return 0;
}
