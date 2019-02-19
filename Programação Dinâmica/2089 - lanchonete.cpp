#include <stdio.h>
#define MAX 1000000
void radixsort(int* vetor, int tamanho) {
    int i;
    int b[tamanho];
    int maior = vetor[0];
    int exp = 1;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    	b[i] = 0;
    }
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
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

int num_moedas(int N, int M, int * m) {
    int dp[N+1];

    // caso base
    dp[0] = 0;

    // sub-problemas
    for(int i=1; i<=N; i++) {
        // é comum atribuir um valor alto, que concerteza
        // é maior que qualquer uma das próximas possibilidades,
        // sendo assim substituido
        dp[i] = MAX;

        for(int j = 0; j < M; j++) {
            if(i-m[j] >= 0) {
                dp[i] = min(dp[i], dp[ i-m[j] ]+1);
            }
        }
    }

    // solução
    return dp[N];
}

int main(){
	int n, b, T, i, j;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &T, &b);
		int B[b];
		int r[T+1];
		int v[b];
		r[0] = 0;
		for(i = 0; i < b; i++)
			scanf("%d", B+i);
			
		for(i = 1; i <= T; i++){
			r[i] = MAX;
			for(j = 0; j < b; j++){
				if(i >= B[j] && r[i] > r[i - B[j]] + 1){
					r[i] = r[i - B[j]] + 1;
				}
			}
		}
		printf("%d\n", r[T]);
	}
	return 0;
}

	
