#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main(){
	int n, quant, qtd, qtdf;
	float preco, result;
	string fruta;
	cin >> n;
	while(n--){
		map<string,float> M;
		map<string,float>::iterator it;
		result = 0.0;
		cin >> qtd;
			while(qtd--){
				cin >> fruta >> preco;
					M.insert(pair<string,float>(fruta,preco));
			}
		cin >> qtdf;
			while(qtdf--){
				cin >> fruta >> quant;
				for(it = M.begin(); it != M.end(); it++){
					if(it->first == fruta){
					preco = it->second;
					result += (quant*preco);
					}
				}
			}
		cout << "R$ " << fixed << setprecision(2) << result << endl;
	}
	return 0;
}
