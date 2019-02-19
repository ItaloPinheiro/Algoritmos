#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>


typedef long long ll;

using namespace std;

ll lim =  sqrt(pow(10,9));
vector<char> calculaPrimos(){
// Vetor para guarda os primos encontrados , já coloco o 2 no vetor para não precisar calcular os numeros pares.
vector<ll> primes; primes.push_back(2);
// Vetor para executar o crivo.
vector<char> isprime(lim, 1);
     // Comando para marca todos os valores do vetor isprime como 1
     for(ll i=3;i<lim;i+=2){
         // Verifico se o numero está marcado com o 1.
         if(isprime[i]){
            // Coloco ele no vetor.
            primes.push_back(i);
            // Marco todos seus múltiplos como não primos (0).
            for(ll j=i*i;j<lim;j+=i){
            //cout << lim << endl;
			isprime[j] = 0;
			}
        }
     }
    return isprime;
}

vector<char> primos = calculaPrimos();

ll aux; // global para poder ser usado no int main caso sobre maior que sqrt(pow(10,9));
bool usaAux; // para verificar se pode usar o aux no int main

vector<ll> fatorar(ll numero){
	vector<ll> fatores(primos.size(),0);
    aux = numero;
    for(ll i=2; i <= primos.size(); i++){ // i < primos.size();
        if(primos[i]){
        	//cout << "primo " << i << " - " << primos[i] << endl;
            while(aux%i == 0){
                fatores[i]++;
                aux = aux/i;
            }
            //cout << "fator " << i << " - " << fatores[i] << endl;
        }
    }
    if(aux > lim) usaAux = true;
    	
    return fatores;
}

int main(){
	//for(ll i = 0; i < primos.size(); i++){cout << primos[i] << endl;}
	int contCasos = 1, casos;
	cin >> casos;
	while(contCasos <= casos){
		usaAux = false;
		ll numero;
		ll resultado = 1;
		cin >> numero;
		vector<ll> fatores = fatorar(numero);
		for(ll i = 2; i < fatores.size(); i++){
			if(fatores[i]){
				if(fatores[i] % 2 != 0){
					fatores[i]++;
				}
			//cout << i << " - " << fatores[i] << endl;
			resultado *= pow(i,fatores[i]);
			}
			if(usaAux){ resultado *= pow(aux,2);
			usaAux = false;
			}
		}
	cout <<"Caso #" << contCasos << ": " << resultado << endl;
	contCasos++;
	}
	return 0;
}
