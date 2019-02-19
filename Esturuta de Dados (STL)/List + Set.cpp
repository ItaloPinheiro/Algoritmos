#include <iostream>
#include <list>
#include <set>
using namespace std;

int main(){
	int n;
	set<int> cii;
	set<int>::iterator it_cii;
	list<int> ci;
	list<int>::iterator it_ci;
	
	for(int i = 0; i < 5; i++){
		cin >> n;
		cii.insert(n);
	}
	it_cii = cii.find(3);
	cii.erase(it_cii);
    for(it_cii = cii.begin(); it_cii != cii.end(); it_cii++){
    	cout << *it_cii << " ";
  		ci.push_back(*it_cii);
	}
	cout << endl;
	for(it_ci = ci.begin(); it_ci != ci.end(); it_ci++){
  		cout << *it_ci << " ";
	}
	cout << endl;
	return 0;
}

