#include <iostream>
#include <cstdlib>
#define MIN -1
#define TAM 5001
using namespace std;

/* ALGORITMO TOP-DOWN CUT-ROD
int cut_aux(int* price, int rod, int* aux){
	int res;
	if(aux[rod] >= 0) return aux[rod];
	if(rod == 0) res = 0;
	else res = MIN;
	for(int i = 1; i <= rod; i++)
		res = max(res, price[i] + cut_aux(price, rod - i, aux));
	
	aux[rod] = res;
	return res;
}

int cut(int* price, int rod){
	int aux[rod];
	for(int i = 0; i < rod; i++)
		aux[i] = MIN;
	
	return cut_aux(price, rod, aux);
}
*/
// ALGORITMO BOTTOM-UP CUT-ROD
int cut(int* price, int rod){
	int aux[rod+1], res;
	aux[0] = 0;
	for(int j = 1; j <= rod; j++){
		res = MIN;
		for(int i = 1; i <= j; i++){
			res = max(res, price[i] + aux[j - i]);
		}
		aux[j] = res;
	}
	return aux[rod];
}

int main(){
	int price[TAM] = {}, rod, N, ind, valor;
	cin >> N >> rod;
	for(int i = 0; i < N; i++){
		cin >> ind;
		cin >> valor;
		if(price[ind] < valor){
			price[ind] = valor;
		}
	}
	int max = cut(price, rod);
	cout << max << endl;
	return 0;
}
