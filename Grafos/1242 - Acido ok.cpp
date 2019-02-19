#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool verifica(char letra, char pilha){
	if((letra == 'B' && pilha == 'S') || (letra == 'S' && pilha == 'B')
	|| (letra == 'C' && pilha == 'F') || (letra == 'F' && pilha == 'C'))	
	return 1;
	return 0;
}

int main(){	
	string seq;
	while(cin >> seq){
		int cont = 0;
		stack<char> pilha;
		pilha.push(seq[0]);
		for(int i = 1; i < seq.size(); i++){
			if(pilha.empty()){
				if(seq[i+1] != '\0'){
					pilha.push(seq[i]);
					continue;
				}else{
					break;
				}
			}
			if(verifica(seq[i], pilha.top())){
				pilha.pop();
				cont++;
			}else{
				pilha.push(seq[i]);
			}
		}
	//cout << "topo da pilha - " << pilha.top() << endl;
	cout << cont << endl;
	}
	return 0;
}
