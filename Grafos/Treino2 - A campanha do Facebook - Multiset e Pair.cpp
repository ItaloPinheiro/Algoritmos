#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main(){
	int x, y, a, b, aux, i;
	vector< vector<int> > vec;
	multiset< pair<int,int> > ci;
	multiset< pair<int,int> >::iterator it;
	cin >> x >> y;
	string res[x+1];
	for (int i = 0; i <= x; i++){
    vec.push_back( vector<int>());
    }
    cin >> a >> b;
  	while(a != 0 && b != 0){
  		vec[a].push_back(b);
  		vec[b].push_back(a);
  	cin >> a >> b;
	}
	for(int i = 1; i < vec.size(); i++){
		aux = vec[i].size();
		ci.insert(pair<int, int>(aux*(-1), i*(-1)));
	}
	for(it = ci.begin(); it != ci.end(); it++){
		cout << it->second*(-1) << " " <<  it->first*(-1) << endl;
	}
	return 0;
}
