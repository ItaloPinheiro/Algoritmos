#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int n, num, a;
	stack<int> pilha;
	vector<int> ci;
	vector<int>::iterator it;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		pilha.push(num);
	}
	while(!pilha.empty()){
		ci.push_back(pilha.top());
		pilha.pop();
	}
	for(it = (ci.end() - 1); it != (ci.begin() - 1); it--){
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}
