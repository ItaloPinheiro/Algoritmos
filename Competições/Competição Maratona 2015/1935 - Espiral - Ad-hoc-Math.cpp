#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
#define lli unsigned long long int
#define li unsigned long int
int main(){
	lli B;
	li N;
	scanf("%lu %llu", &N, &B);
	li cord_x = 1, cord_y = 1;
	li sub_x = 1, sub_y = 1;
	li tam = N;
	lli grao = B;
	while(grao - (tam*4 - 4) > 0){
		//printf("grao -> %llu / tam -> %lu\n", grao, tam);
		sub_y++;
		
		sub_x++;
		grao = grao - (tam*4 - 4);
		tam -= 2;
	}
	printf("grao sobrando -> %llu\n", grao);
	printf("x -> %lu / y -> %lu / tam -> %lu\n", sub_x-1, sub_y, tam);
	//printf("%ld - %lld\n", N, B);
	system("pause");
	return 0;
}
