#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int main(){
	string N;
	int p, l, c;
	while(scanf("%d", &p) != EOF){
		vector<int> vet;
		int i = 0, pags = 0 , cc, cl = 0;
		string palavra;
		scanf("%d %d", &l, &c);
		getchar();
		for(i = 0; i < p; i++){
			cin >> palavra;
			vet.push_back(palavra.size());
		}
		i = 0;
		while(i < p){
			cc = 0;
			while(cc < c){
				cc += vet[i++] + 1;
			}
			if(cc - 1 > c) i--;
			cl++;
		}
		if(cl % l == 0) pags = cl / l;
		else pags = (cl / l) + 1; 
		printf("%d\n", pags);
	}
    return 0;
}
