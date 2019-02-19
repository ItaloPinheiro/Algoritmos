#include <iostream>
#include <cstdlib>
#define MAX 1000
using namespace std;

/* Printando descrescente sem recursividade
void print(int l[][MAX], int slinha, int nEstacao){
	int i = slinha, j;
	cout << "linha " << i << ", estacao " << nEstacao << endl;
	for(j = nEstacao; j >= 2; j--){
		i = l[i][j];
		cout << "linha " << i << ", estacao " << j - 1 << endl;
 	}	
}
*/

//Printando crescente com recursividade
void print(int l[][MAX], int slinha, int nEstacao){
	int i = slinha;
	if(nEstacao >= 1){
		print(l, l[i][nEstacao], nEstacao - 1);
		cout << "linha " << i << ", estacao " << nEstacao << endl;
	}
}

int main(){
	int nEstacao, e1, e2, s1, s2, min, slinha, i;
	cout << "Numero de estacoes: "; cin >> nEstacao;
	int estacao[3][nEstacao+1], trans[3][nEstacao];
	int l[3][MAX], f[3][nEstacao+1];
	cout << "Entrada linha 1: "; cin >> e1;
	cout << "Entrada linha 2: "; cin >> e2;
	cout << "Saida linha 1: "; cin >> s1;
	cout << "Saida linha 2: "; cin >> s2;
	cout << "Tempo das estacoes: " << endl;
	
	for(i = 1; i <= nEstacao; i++)
		cin >> estacao[1][i]; 
		
	for(i = 1; i < nEstacao; i++)
		cin >> trans[1][i];
		
	for(i = 1; i <= nEstacao; i++)
		cin >> estacao[2][i];
		
	for(i = 1; i < nEstacao; i++)
		cin >> trans[2][i];
	
	
	f[1][1] = e1 + estacao[1][1];
	f[2][1] = e2 + estacao[2][1];
	
	for(i = 2; i <= nEstacao; i++){
		int vl1 = f[1][i - 1] + estacao[1][i];
		int vl2 = f[2][i - 1] + trans[2][i - 1] + estacao[1][i];
		if(vl1 <= vl2){
			f[1][i] = vl1;
			l[1][i] = 1;
		} else{ 
			f[1][i] = vl2;
			l[1][i] = 2;
		}
		vl1 = f[2][i - 1] + estacao[2][i];
		vl2 = f[1][i - 1] + trans[1][i - 1] + estacao[2][i];
		if(vl1 <= vl2){
			f[2][i] = vl1;
			l[2][i] = 2;
		} else{ 
			f[2][i] = vl2;
			l[2][i] = 1;
		}		
	}
	if(f[1][nEstacao] + s1 <= f[2][nEstacao] + s2){
		min = f[1][nEstacao] + s1;
		slinha = 1;
	} else{
		min = f[2][nEstacao] + s2;
		slinha = 2;
	}
	
	print(l, slinha, nEstacao);
}
/* casos de teste
6
2 
4
3 
2
7 9 3 4 8 4
2 3 1 3 4
8 5 6 4 5 7
2 1 2 2 1
*/
