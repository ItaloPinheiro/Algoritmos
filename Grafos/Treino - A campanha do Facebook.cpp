#include <iostream>
#include <vector>

using namespace std;

int main(){
	int x, y, a, b, max, pos, i;
	vector< vector<int> > vec;
	cin >> x >> y;
	for (int i = 0; i <= x; i++){
    vec.push_back( vector<int>());// Create an empty row
    }
    cin >> a >> b;
  	while(a != 0 && b != 0){
  		vec[a].push_back(b);
  		vec[b].push_back(a);
  	cin >> a >> b;
	}
	for(i = 1; i < vec.size(); i++){
		cout << i << "- ";
		for(int j = 0; j < vec[i].size(); j++){
		cout << vec[i][j] << "- ";
		}
	cout << endl; 
	}
	/*
	for(int j = 0; j < x; j++){
		max = vec[1].size(); pos = 1;
		for(int i = vec.size(); i >= 2; i--){
			if(max < vec[i].size()){
				max = vec[i].size();
				pos = i;
			}
		}
	cout << pos << " " << max << endl;
		for(int i = pos; vec[pos].size(); i++)
			vec[pos].pop_back();
	}
	*/
	return 0;
}
