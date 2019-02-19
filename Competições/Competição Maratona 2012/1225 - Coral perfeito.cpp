#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int N, i, j, num;
	while(scanf("%d", &N) != EOF){
		int vet[N+1], soma = 0, ans = 0, media;
		bool aux = true;
		for(i = 0; i < N; i++){
			scanf("%d", &num);
			soma += num;
			vet[i] = num;
		}
		if((soma % N) != 0){
			puts("-1");
			continue;
		}
		media = soma/N;
		for(i = 0; i < N; i++){
			if(media > vet[i]){
				ans += media - vet[i];
			}
		}
		printf("%d\n", ans+1);
	}
	
}
