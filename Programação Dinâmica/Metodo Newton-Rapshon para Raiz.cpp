#include<stdio.h>
#include<math.h>

int main(){
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) && a != 0){
	double x0 = (a*b*c), x1 = (a*b*c) / 3.0;
		for(int i = 0; i < 50; i++){
			x1 = (1.0/3.0)*((2*x1) + (x0/(x1*x1)));
		}
		int r = x1;
		printf("%d\n", r);
		//printf("%lf\n", x1);
	}
	return 0;
}
