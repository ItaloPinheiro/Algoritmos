#include <stdio.h>
#include <iostream>
#include <string.h>
#include <list>
#include <stdlib.h>
using namespace std;

int main(){
	int n, d;
	while(scanf("%d %d", &n, &d) && n!=0){
		getchar();
		int cont = 0, i;
		char v[n+1];
		gets(v);
		list<char> l;
		list<char>::iterator it_l;
		l.push_back(v[0]);
		for(i = 1; i < n; i++){
			it_l = l.end();
			it_l--;
			if(cont == d) break;
			while((*(it_l) < v[i] && !l.empty() && cont != d)){
				it_l--;
				l.pop_back();
				cont++;
			}
			l.push_back(v[i]);
		}
		while(cont < d){
			l.pop_back();
			cont++;
		}
		for(it_l = l.begin(); it_l != l.end(); it_l++){
			printf("%c", *(it_l));
		}
		for(; i < n; i++){
			printf("%c", v[i]);
		}
		puts("");
	}
	return 0;
}
