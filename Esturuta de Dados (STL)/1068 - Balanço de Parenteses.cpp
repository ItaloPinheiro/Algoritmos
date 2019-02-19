#include <iostream>
#include <stack>

using namespace std;

int main(){
	int aux;
	string v;
	while(cin >> v){
		stack<char> ci;
		aux = 0;
		for(int i = 0; v[i]; i++){
			if(v[i] == '(')
				ci.push(v[i]);
			else if(v[i] == ')' && !ci.size()){
			    aux = 1; 
				break;
			}
			else if (v[i] == ')')
				ci.pop();
		}
		if(ci.size() || aux)
			cout << "incorrect" << endl;
		else if(!ci.size() && !aux)
			cout << "correct" << endl;
	}
}
