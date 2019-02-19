#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(){
		int casos, i;
		scanf("%d", &casos);
		while(casos--){
			int bolas;
			scanf("%d", &bolas);
			int brancax, brancay, bolax, bolay;
			int *bmenor = malloc(sizeof(int));
			float *distmenor = malloc(sizeof(float));
			float *distatual = malloc(sizeof(float));
			scanf("%d %d", &brancax, &brancay);
			for(i = 0; i < bolas; i++){
				scanf("%d %d", &bolax, &bolay);
				if(!i){
				*bmenor = 0; *distmenor = 1000000.0;}
				*distatual = (float) sqrt((pow(brancax - bolax , 2)) + (pow(brancay - bolay , 2)));
				if(*distmenor > *distatual){
					*bmenor = i+1;
					*distmenor = *distatual;
				}else if(*distmenor == *distatual){
					if(*bmenor > i+1){
						*bmenor = i+1;
						*distmenor = *distatual;
					}
				}
			}
			printf("%d\n", *bmenor);
			free(bmenor);
			free(distmenor);
			free(distatual);
		}
}
