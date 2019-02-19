#include <stdio.h>
#define MAX 1000000
int main(){
	int n, b, T, i, j;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &b, &T);
		int B[b];
		int r[T+1];
		r[0] = 0;
		for(i = 0; i < b; i++){
			scanf("%d", B+i);
		}
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
