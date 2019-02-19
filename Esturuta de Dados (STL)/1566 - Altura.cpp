#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, nalt, alt, aux;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &nalt);
		aux = 1;
		vector<int> ci;
		vector<int>::iterator it;
		while(nalt--){
			scanf("%d", &alt);
			ci.push_back(alt);
		}
		sort(ci.begin(), ci.end());
		for(it = ci.begin(); it != ci.end(); it++){
			if(aux){
			printf("%d", *it);
			it++; aux = 0;
			}
			printf(" %d", *it);
		}
	printf("\n");
	}
}
