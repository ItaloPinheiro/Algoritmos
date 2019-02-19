#include <iostream>

using namespace std;
int calcmdc(int a, int b){
	if(b == 0)
	return a;
	return calcmdc(b , a % b);
}

int main(){
	int n, num, den, mdc;
	int n1, d1, n2, d2;
	char x, oper;
	cin >> n;
	while(n--){
		cin >> n1 >> x >> d1 >> oper >> n2 >> x >> d2;
		switch(oper){
			case '+': num = (n1 * d2 + n2 * d1);
					  den = (d1*d2);
			break;
			case '-': num = (n1 * d2 - n2 * d1);
					  den = (d1*d2);
			break;
			case '*': num = (n1 * n2);
					  den = (d1 * d2);
			break;
			case '/': num = (n1 * d2);
					  den = (d1 * n2);
		}
		mdc = calcmdc(num,den);
		cout << num << "/" << den << " = ";
		if(den < 0 ){
			num *= (-1);
			den *= (-1);
		}
		if(mdc < 0)
			mdc *= (-1);
		
		cout << num/mdc <<"/" << den/mdc << endl;
		num = 0; den = 0;
	}
	return 0;
}


