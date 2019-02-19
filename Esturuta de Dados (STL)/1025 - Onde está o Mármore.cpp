#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, q, num, caso = 1;
	cin >> n >> q;
	while(n && q){
		vector<int>vec;
		for(int i = 0; i < n; i++){
			cin >> num;
			vec.push_back(num);
		}
		sort(vec.begin(), vec.end());
		cout << "CASE# " << caso << ":\n";
		for(int i = 0; i < q; i++){
			cin >> num;
			int aux = 0;
			for(int j = 0; j < vec.size() ; j++)
				if(vec[j] == num){
					cout << num << " found at " << j+1 << endl;
					aux = 1;
					break;
				}
			if(!aux) cout << num << " not found\n";
		}
		cin >> n >> q; caso++;
	}
	return 0;
}
