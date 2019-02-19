#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <list>

using namespace std;

vector< vector<int> > g; // Lista de Adjac�ncia

// Algoritmo calcula a menor distancia para alcan�ar todos os vertices do grafo partindo de um vertice inicial.
vector<int> bfs(int inicio){
	//para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de dist�ncia minima para alcan�ar o vertice.
    vector<int> p(g.size(), -1); // Vetor que armazena o pai de cada vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou n�o.
    
	queue<int> Q; // Fila que define a ordem de acesso aos vertices.
	
	// Inicializa��o
    cor[inicio] = true; // Define a cor do v�rtice raiz como acessado.
    d[inicio] = 0; // Define a dist�ncia da raiz para ela mesma como 0.
    
    Q.push(inicio); // Enfileira a raiz.
    
    // Enquanto a fila n�o estiver vazia.
    while(!Q.empty()){
        int u = Q.front(); // Define u como sendo o v�rtice na frente na fila.
        Q.pop(); // Desenfileira.
        
        // Para todo vertice adjacente � "u".
        for(int i = 0; i < g[u].size(); i++){
            // Se o vertice adjacente � "u" n�o tiver sido encontrado.
			if(cor[g[u][i]] == false){
                Q.push(g[u][i]); // Enfileira o vertice adjacente.
                cor[g[u][i]] = true; // Define o vertice adjacente como encontrado.
                d[g[u][i]] = d[u]+1; // Define a distancia minima para alcan�ar o vertice.
                p[g[u][i]] = u; // Define o pai do vertice adjacente como "u".
            }
        }
    }
    
    // *** OBS: O RETORNO DA FUN��O PODE SER ALTERADO CONFORME A NECESSIDADE DO PROBLEMA. ***
    return d; // Retorna o vetor peso.
}

int main(){
	int num, aux, resto;
	g.resize(10001);
	for(int i = 1; i < 10000; i++){
		g[i].push_back(i+1);
		aux = i; num = 0; resto = 0;
		while(aux){
			resto = aux % 10;
			num = num * 10 + resto;
			aux /= 10;
		}
		g[i].push_back(num);
		cout << i << " - " << num << endl;
	}
	int casos, inicio, fim;
	cin >> casos;
	while(casos--){
		cin >> inicio >> fim;
		vector<int> dist = bfs(inicio);
		cout<<dist[fim]<<endl;
	}
	return 0;
}
