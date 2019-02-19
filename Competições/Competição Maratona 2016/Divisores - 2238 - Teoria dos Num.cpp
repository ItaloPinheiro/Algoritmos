#include <iostream>
#include <set>
#include <math.h>
using namespace std;
int main(){
	long long int a, b, c, d, e, i;
 	cin >> a >> b >> c >> d;
	set<int> num;
	for(i = 1; i <= sqrt(c); i++){
		if(c % i == 0){
			e = c / i;
			if(i % a  == 0 && i % b != 0 && d % i != 0){
				num.insert(i);
			}
			if(e % a == 0 && e % b != 0 && d % e != 0){
				num.insert(e);
			}
		}
	}
	if(!num.size()) puts("-1");
	else cout << *num.begin() << endl;
	system("pause");
	return 0;
}
