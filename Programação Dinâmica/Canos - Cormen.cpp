#include <iostream>
#include <cstdlib>
#define MIN -1
#define TAM 10
using namespace std;

// ALGORITMO TOP-DOWN CUT-ROD
int cut_aux(int* price, int rod, int* aux){
	int res;
	if(aux[rod] >= 0){
		cout << "retornando aux[" << rod << "] >= 0 valor -> "<< aux[rod] << endl;
		return aux[rod];
	}
	if(rod == 0){ 
		res = 0;
		cout << "entrou rod = 0" << endl; 
	}
	else res = MIN;
	for(int i = 1; i <= rod; i++){
		cout << endl << "rodando corte " << i << " tamanho rod - > " << rod << endl;
		cout << "resultado atual -> " << res << " / price[" << i << "] -> " <<
		price[i] << " + cut_aux(price, " << rod << " - " << i << ", aux)" << endl << endl;
		res = max(res, price[i] + cut_aux(price, rod - i, aux));
		cout << "saindo do for -> " << res << " / i -> " << i << endl;
	}
	aux[rod] = res;
	cout << "retornando e gravando res = " << res << " em aux[" << rod << "]" << endl;
	return res;
}

int cut(int* price, int rod){
	int aux[rod+1];
	for(int i = 0; i <= rod; i++)
		aux[i] = MIN;
	
	return cut_aux(price, rod, aux);
}

/* ALGORITMO BOTTOM-UP CUT-ROD
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

*/
int main(){
	int price[TAM] = {}, rod;
	cout << "tam da haste: "; cin >> rod;
	for(int i = 1; i <= rod; i++){                                     
		cout << i << " - ";
		cin >> price[i];
	}
	
	int max = cut(price, rod);
	cout << "max: " << max << endl;
	return 0;
}
