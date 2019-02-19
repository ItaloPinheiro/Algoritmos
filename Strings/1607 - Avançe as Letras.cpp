#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int num, n, valor;
	string s, ss;
	cin >> n;
	while(n--){
		cin >> s >> ss;
		num = 0; valor = 0;
		for(int j = 0; j < s.length(); j++){
			num = ss[j] - s[j];
			if(num < 0)
				valor += num + 26;
			else
				valor += num;
		}
	cout << valor << endl;
	}
	return 0;
}
