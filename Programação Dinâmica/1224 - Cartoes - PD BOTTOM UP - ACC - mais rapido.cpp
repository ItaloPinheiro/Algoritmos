#include <stdio.h>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int i, j, k; // variaveis de incrementação
	int res, pres; // variaveis de acesso
	long long int re, rd; // variaveis de valores resultantes da logica pela esq. e dir.
	while(scanf("%d", &n) != EOF){
		getchar();
		int v[n+1]; // vetor de cartoes
		long long int m[2][n+1]; // matriz auxiliar de cartoes
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);
			
		for(i = 0; i < n-1; i++)
			m[0][i] = max(v[i], v[i+1]);
		
		res = 0;
		for (i = 4; i <= n; i += 2){
			pres = res; // essa logica de pres e res é para tornar pres em res e mudar o valor de res para 1, dps para 0 e assim vai
			res = 1 - res;
			for (k = 0; k <= n - i; k++){
				j = i + k - 1;
				re = v[k] + max(m[pres][k+1], m[pres][k+2]);
				rd = v[j] + max(m[pres][k], m[pres][k+1]);
				m[res][k] = max(re, rd);
			}
		}
		printf("%lld\n", m[res][0]);
		//system("pause");cion
	}
	return 0;
}

