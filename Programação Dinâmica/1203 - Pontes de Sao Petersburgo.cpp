#include <stdio.h>

int main(){
	int r, p, a, b, i, j;
	while(scanf("%d %d", &r, &p) != EOF){
		int v[r+1];
		int l[p+1];
		for(i = 1; i <= r; i++) v[i] = 0;
		for(i = 1; i <= p; i++) l[i] = 0;
		
		for(i = 1; i <= p; i++){
			scanf("%d %d", &a, &b);
			v[a]++;
			v[b]++;
		}
		l[0] = 1;
		for(i = 1; i <= r; i++){
			for(j = p; j >= v[i]; j--){
				if(l[j - v[i]] == 1) l[j] = 1; 
				
			}
		}
		if(l[p] == 1) puts("S");
		else puts("N");
	}
	return 0;
}
