#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> ci;
	list<int>::iterator it_ci;
	
	for(int i = 0; i <= 5; i++){
		ci.push_front(i);
	}
	while (!ci.empty()){
    for(it_ci = ci.begin(); it_ci != ci.end(); it_ci++){
  		cout << *it_ci << " ";
	}
	cout << endl;
	ci.pop_back();
  	}
  	for(int i = 0; i <= 5; i++){
		ci.push_front(i);
	}
	while (!ci.empty()){
    for(it_ci = ci.begin(); it_ci != ci.end(); it_ci++){
  		cout << *it_ci << " ";
	}
	cout << endl;
	ci.pop_front();
  	}
	return 0;
}
