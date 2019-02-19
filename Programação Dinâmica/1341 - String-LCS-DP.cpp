#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int LCS(string a, string b){
	int m = a.length(), n = b.length();
	if(!m || !n) return 0;
	int i, j, Z[m+1][n+1];
	
	for(i = 0; i <= m; i++)
		for(j = 0; j <= n; j++)
			if(!i || !j)
				Z[i][j] = 0;
			else if(a[i - 1] == b[j - 1])
				Z[i][j] = Z[i-1][j-1] + 1;
			else 
				Z[i][j] = max(Z[i-1][j], Z[i][j-1]);

	return Z[m][n];
}

int main(){
	int cases, nstr, tamstr, i, j, c = 1;
	scanf("%d", &cases);
	while(c <= cases){
		scanf("%d %d", &nstr, &tamstr);
		string mapa[nstr], caminho = "", caminho1= "", str= "", str1 = "";
		for(i = 0; i < nstr; i++)
			cin >> mapa[i];

		int Xo, Xo1, Yo, Yo1, nc, nc1;
		scanf("%d %d %d", &nc, &Xo, &Yo);
		if(nc) cin >> caminho;
		scanf("%d %d %d", &nc1, &Xo1, &Yo1);
		if(nc1) cin >> caminho1;
		Xo--; Yo--; Xo1--; Yo1--;
		//printf("%c %c %c", mapa[0][0], mapa[1][2], mapa[2][3]);
		
		str += mapa[Xo][Yo];
		if(nc){
			for(i = 0; i < caminho.length(); i++){
				switch(caminho[i]){
					case 'N': Xo--;
						break;
					case 'S': Xo++;
						break;
					case 'E': Yo++;
						break;
					case 'W': Yo--;
				}
			//	printf("vendo letra %c\n", caminho[i]);
			//	printf("matriz[%d][%d] = %c\n", Xo, Yo, mapa[Xo][Yo]);
			str += mapa[Xo][Yo];
			}
		}
		str1 += mapa[Xo1][Yo1];
		if(nc1){
			for(i = 0; i < caminho1.length(); i++){
				switch(caminho1[i]){
					case 'N': Xo1--;
						break;
					case 'S': Xo1++;
						break;
					case 'E': Yo1++;
						break;
					case 'W': Yo1--;
				}
			//	printf("vendo letra %c\n", caminho[i]);
			//	printf("matriz[%d][%d] = %c\n", Xo, Yo, mapa[Xo][Yo]);
				str1 += mapa[Xo1][Yo1];
			}
		}
		int tam = LCS(str, str1);
		printf("Case %d: %d %d\n", c, str.length() - tam, str1.length() - tam);
		c++;
	}
}
