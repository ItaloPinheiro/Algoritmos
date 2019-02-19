#include <stdio.h>
#include <climits>
#include <algorithm>

using namespace std;
int main(){
	int n;
	int i, j, k;
	long long int soma;
	int ctrl, vctrl, auxc;
	while(scanf("%d", &n) != EOF){
		getchar();
		vctrl = 1;
		long long int m[3][n+1];
		for(i = 1; i <= n; i++){
			scanf("%lld", &m[0][i]);
			m[1][i] = m[0][i];
			m[2][i] = m[0][i];
		}	
		for (i = 1; i <= n - 1; i++){
			j = i + 1;
			//ctrl controla a parte de soma
			//auxc controla a busca pelo numero para complementar a soma
			for (k = 1, ctrl = 1, auxc = vctrl; k <= n - i; k++, ctrl++, auxc++){
				
				soma = m[2][ctrl] + m[0][auxc + 1];
				//printf("\nsoma = (m[%d][%d] + m[%d][%d]) = %d - min(%d)\n", 1, k, 1, k+1, soma, min(m[1][k], m[1][k+1]));
				//printf("resultando em: %d\n", soma - min(m[1][k], m[1][k+1]));
				m[1][k] = soma - min(m[1][k], m[1][k+1]);
				//printf("valor atual de soma = %d/ valor a ser somado = %d\n", m[2][ctrl], m[0][auxc+1]);
				m[2][ctrl] += m[0][auxc+1];
			}
			vctrl++;
		}
		printf("%lld\n", m[1][1]);
		//system("pause");
	}
	return 0;
}

