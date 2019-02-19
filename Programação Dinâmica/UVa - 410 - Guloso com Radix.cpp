#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

void radixsort(int* vetor, int tamanho) {
    int i, b[tamanho], maior = vetor[0], exp = 1;

	for (i = 0; i < tamanho; i++)
        b[i] = 0;
    
    
    for (i = 0; i < tamanho; i++) 
        if (vetor[i] > maior)
    	    maior = vetor[i];
    
 
    while (maior/exp > 0) {
        int bucket[10] = {};
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }
}
int busca(int* spc, int p, int s, int tam){
	for(int i = 0; i < tam; i++){
		if(spc[i] == p) return p;
		if(spc[i] == s) return s;
	}
}
int main(){
	int C, S, set = 0, p, s;
	while(scanf("%d %d", &C, &S) != EOF){
		vector< pair<int, int> > vec;
		vector<int> vec_b(C+1, 0);
		int tam = 2*C;
		int spc[tam], Aspc[tam], i, j;
		double imb = 0, m = 0;
		
		for(i = 0; i < 2*C; i++)
			Aspc[i] = 0;
		if(S < tam){
			for(i = (tam - S); i < S + (tam - S); i++){
				scanf("%d", spc+(i-1));
				Aspc[i] = spc[i-1];
				m += spc[i-1];
			}
		}else{
			for(i = 0; i < S; i++){
				scanf("%d", spc+(i-1));
				Aspc[i] = spc[i-1];
				m += spc[i-1];
			}
		}
		m /= C;
		
		printf("Set #%d\n", ++set);
		radixsort(Aspc, tam);
			
		for(i = 0, j = tam-1; i < j; i++, j--){
			//printf("%d - %d\n", Aspc[i], Aspc[j]);
			imb += fabs((Aspc[i] + Aspc[j]) - m);
			vec.push_back(make_pair(Aspc[i], Aspc[j]));
		}
		int cont = 0;
		for(i = 0; i < S; i++){
			for(j = 0; j < C; j++){
				if(!vec_b[j]){
					p = vec[j].first; s = vec[j].second;
					//printf("spc[%d] = %d\n", i, spc[i]);
					//printf("%d - %d\n", p, s);
					if(p && s){
						if(spc[i] == p || spc[i] == s){
							if(busca(spc, p, s, tam) == p)
								printf(" %d: %d %d\n", cont++, p, s);
							else
								printf(" %d: %d %d\n", cont++, s, p);
							vec_b[j] = 1;
						}
						/*
						else if(spc[i] == s){
							printf("%d: %d %d\n", 0, s, p);
							vec_b[j] = 1;
						}*/
					}else{
						if(spc[i] == s){
					 		printf(" %d: %d\n", cont++, s);
					 		vec_b[j] = 1;
					 	}
					}
				}
			}
			//puts("-------------------------");
		}
		printf("IMBALANCE = %.5lf\n", imb);
		puts("");
	}
}




