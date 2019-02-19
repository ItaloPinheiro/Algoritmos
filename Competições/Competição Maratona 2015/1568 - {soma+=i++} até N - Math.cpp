#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define lli unsigned long long
#define LIM 3000001

using namespace std;

bitset<LIM+1> isprime;
vector<lli> prime;
lli prime_cont = 0;
lli lim = LIM;

void n_primos(){
    isprime.set();
    prime.resize(LIM+1);
	prime[prime_cont++] = 2;
	
	for(lli i=3; i<=lim; i+=2)
		if(isprime[i]){
			prime[prime_cont++] = i;

			for(lli j=i*i; j<=lim; j+=i)
				isprime.reset(j);
		}
	//printf("done with %llu primes.\n", prime_cont);
}
int main(){
	lli n;
	int res = 1, i = 0, d = 0;
	n_primos();
	while(scanf("%llu", &n) != EOF){
	    while(n > 2){
			d = 0;
			//printf("prime_cont -> %llu\n", prime_cont);
			if(i < n && i >= prime_cont){
				//printf("n -> %llu\n", n);
				res *= 2;
				break;
			}
			while(n > 2 && n % prime[i] == 0){
				n /= prime[i];
				//puts("entrou");
				d++;
			}
			if(i) res *= (d+1);
			//printf("valor de i -> %d\n", i);
			i++;
		}
		printf("%d\n", res);
		res = 1; i = 0; d = 0;
	}
	system("pause");
	return 0;
}
