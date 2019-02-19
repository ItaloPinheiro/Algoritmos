#include <iostream>
#include <cstdlib>
#define ull unsigned long long int
#define MAX 1000

using namespace std;

ull fib(int n, ull &cont, ull &v){
	cont++;
	if(n == 2) return 1;
	
	if(!v[n])
		v[n] = fib(n-1, cont, v)+ fib(n-2, cont, v);
	return v[n];

}

ull chamada(int n, ull &v2){
	if(n == 0 || n == 1) 
		return 0;
		
	if(!v2[n])
		v2[n] = (chamada(n-1, v2)+1)+(chamada(n-2, v2)+1);
	return v2[n];
}

int main(){
	int casos, num;
	cin >> casos;
	while(casos--){
		ull v[MAX]= {};
		ull v2[MAX]= {};
		ull cont = -1;
		v[0] = 0;
		v[1] = 1;
		cin >> num;
		ull res = fib(num, cont, v);
		ull call = chamada(num, v2);
		cout << "Fib("<< num <<") = " << res << " / " << call << "chamadas recursivas"<< endl;
		cout << "Com DP serao " << call << "chamadas recursivas" << endl;
	}	
	return 0;
}
