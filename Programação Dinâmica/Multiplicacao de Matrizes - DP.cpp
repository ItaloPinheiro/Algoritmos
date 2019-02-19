#include <stdio.h>
#include <climits>
#define Maxn 10
int main(int argc, char *argv[]){
	int i, j, k, l, n, q;
	int b[Maxn+1];
	int m[Maxn][Maxn] = {};
	int s[Maxn][Maxn];
	printf("Numero de matrizes n: ");
	scanf("%d", &n);
	getchar();
	printf("Dimensoes das matrizes: ");
	for (i = 0; i <= n; i++){
		printf("\n%d -> ", i);
		scanf("%d", &b[i]);	
	}
	for (i = 1; i <= n; i++)
		m[i][i] = 0;
		
	puts("");
	for (l = 2; l <= n; l++){
		for (i = 1; i <= n - l + 1; i++){
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++){
				q = m[i][k] + m[k+1][j] + b[i-1] * b[k] * b[j];
				
				printf("\nm[%d][%d] + m[%d][%d] + b[%d] * b[%d] * b[%d]\n",
						i, k, k+1, j, i-1, k, j);
				printf("  %d  +   %d  +  %d  *  %d  *  %d\n\n", 
						m[i][k], m[k+1][j], b[i-1], b[k], b[j]);
				
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		printf("m[%d][%d] = %d\n", i, j, m[i][j]);
		printf("s[%d][%d] = %d\n", i, j, s[i][j]);
		}
	puts("");
	}
return 0;
}

