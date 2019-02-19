#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	string s;
	while(getline(cin, s) != EOF){
		int cont = 0;
		char ini = s[0];
		for(i = 1; i < s.size(); i++){
			if(v[i] == ' ' && v[i+1] != '\0'){
				if(ini != v[i+1] && next){
					ini = v[i+1];
					next = false;
				}
				else if(tolower(ini) == tolower(v[i+1]){
					cont++;
					next = true;
				}
			}
		}
		printf("%d\n", cont);
	}	
}

