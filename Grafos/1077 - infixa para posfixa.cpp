#include <iostream>
#include <vector>
#include <string>
#include <stack>
 
 
using namespace std;
 
int main() {
    int casos;
    string entrada;
    char caracter;
    vector<int> p(120,-1);
    p['(']=0; p['+']=1; p['-']=1;
    p['*']=2; p['/']=2; p['^']=3;
    cin >> casos;
    while(casos--){
    	stack <char> pilha;
        cin >> entrada;
        for (int i=0; i<entrada.size(); i++) {
            caracter = entrada[i];
            if (caracter == '-' || caracter == '+' || caracter == '/' || caracter == '^' || caracter == '*' || caracter == '(' || caracter == ')' ){
                if (pilha.empty() || caracter == '('){
                    pilha.push(caracter);
                } else if (caracter == ')'){
                    while(!pilha.empty() && pilha.top() != '(' ) {
                        cout << pilha.top();
                        pilha.pop();
                    }
                    if(pilha.top() == '(') pilha.pop();
                } else {
                    while (!pilha.empty()  && p[pilha.top()] >= p[caracter] ) {
                    	cout << pilha.top();
                    	pilha.pop();
                	}
                pilha.push(caracter);
                }
            } else {
                cout << caracter;
            }
    	}
        while (!pilha.empty()) {
            cout << pilha.top();
            pilha.pop();
        }
        cout << endl;
    }
 
 
    return 0;
}
