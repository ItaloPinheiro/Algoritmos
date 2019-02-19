#include <iostream>
#include <set>
using namespace std;

int main(){	
	int n, h, v, t;
	while(cin >> n >> h){
		multiset< pair<int, int> > set;
		multiset< pair<int, int> >::iterator it;
		int vet[n+1], tot = 0;
		for(int i = 1; i <= n; i++){
			vet[i] = 0; 
		}
		for(int i = 0; i < n; i++){
			cin >> v >> t;
			set.insert(make_pair(-v,t));
			tot += v;
		}
		/*
		for(it = set.begin(); it != set.end(); it++){
			cout << it->first << " " << it->second << endl;
		}
		*/
		it=set.begin();
		while(h > 0 && it != set.end()){
			if(!vet[it->second]){
				tot += it->first;
				vet[it->second] = 1;
				h--;
			}else{
				for(int i = it->second; i > 0; i--){
					if(!vet[i]){
						//cout << "hora - " << i << endl;
						vet[i] = 1;
						tot += it->first;
						h--;
						break;
					}
				}
			}
		it++;
		}
	cout << tot << endl;
	}
	return 0;
}
