#include <iostream>
using namespace std;

int main(){
	int N, i, j, num;
	while(scanf("%d", &N) != EOF){
		int pass = 0, cont, aux, pc;
		int largada[N+1], chegada[N+1];
		int pos_c[N+1];
		for(i = 1; i <= N; i++){
			scanf("%d", &num);
			largada[i] = num;
		}
		for(i = 1; i <= N; i++){
			scanf("%d", &num);
			chegada[i] = num;
			pos_c[num] = i;
		}
		for(i = 1; i <= N; i++){
			pc = pos_c[largada[i]];
			if(pc < i){
				cont = i;
				while(cont > pc){
					//printf("entrou %d\n", i);
					aux = largada[cont-1];
					largada[cont-1] = largada[cont];
					largada[cont] = aux;
					cont--;
				}
				//exibindo o vetor largada
				//printf("vetor largada:\n");
				//for(j = 1; j <= N; j++)
				//	printf("%d ", largada[j]);
				//puts("\n");
				pass += i - pc;
				i = 0;
			}
		}
		printf("%d\n", pass);
		//puts("------------------------------------------");
	}
}
