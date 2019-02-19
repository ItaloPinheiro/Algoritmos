#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

int main(){
int num=0, num1=0, snum=0;
string ssnum;
	cin >> num >> num1;
	while(num != 0 && num1 != 0){
	stringstream aux;
	snum = num + num1;
	aux << snum;
	aux >> ssnum;
		for(int i = 0; ssnum[i]; i++){
			if(ssnum[i] != '0')
				cout << ssnum[i];
		}
	cout << endl;
	ssnum=""; snum=0;
	cin >> num >> num1;
	}
return 0;
}
