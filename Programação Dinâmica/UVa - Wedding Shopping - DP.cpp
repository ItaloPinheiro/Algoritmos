#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#define MAX -10^6

using namespace std;

int M, C, price[25][25];
int memo[210][25];

int shop(int money, int g){
	if(money < 0){
		//puts("\nreturning MAX");
		return MAX;
	}
	if(g == C){
		//printf("\n%d == %d\n", g, C);
		//printf("returning value = %d\n", M - money);
		return M - money;
	}
	if(memo[money][g] != -1){
		//puts("value already have memoized");
		//printf("memo[%d][%d] = %d", money, g, memo[money][g]);
		return memo[money][g];
	}
	int ans = -1;
	for(int model = 1; model <= price[g][0]; model++){
		//printf("\nrunning: shop(money = %d - price[%d][%d] = %d, g = %d)",
		//		money, g, model, price[g][model], g);
		ans = max(ans, shop(money - price[g][model], g + 1));
		//printf("\nANS = %d\n", ans);
	}
//	puts("\n-----after for------");
//	printf("returning memo[%d][%d] = %d\n", money, g, ans);
	return memo[money][g] = ans;
}

int main(){
	int i, j, cases, score;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d %d", &M, &C);
		for(i = 0; i < C; i++){
			scanf("%d", &price[i][0]); //first number is the amount garment 
			for(j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		memset(memo, -1, sizeof memo);
		score = shop(M, 0);
		if(score < 0) printf("no solution\n");
		else printf("%d\n", score);
		//puts("\n*************************************************************************");
	}
	return 0;
}
