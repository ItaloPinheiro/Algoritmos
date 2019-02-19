#include<iostream>
#include<vector>
#include<list>
#include <cstdlib>

#define PRETO 0 // Descendentes j? est?o pretos ou n?o tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // N?o descoberto.
#define AZUL 3 //ta na fila
using namespace std;

vector< vector<int> > g; // Lista de Adjacência
vector< vector<bool> > matriz;
vector<bool> aberto;
vector<bool> tentado;
vector<int> cor;

bool TNA(list<int> &lista){
	list<int>::iterator it;
	//visualizar a fila
	 /*for(it = lista.begin(); it != lista.end(); it++){
		cout << *it << " - ";
	}
	cout << endl;
	*/
	for(it = lista.begin(); it != lista.end(); it++){
		if(aberto[*it]){return true;}	
	}
	return false;
}
// Algoritmo calcula a menor distancia para alcançar todos os vertices do grafo partindo de um vertice inicial.
bool bfs(int inicio){
	
	cor[1] = CINZA;
	//para os 3 vetores a seguir, cada posição do vetor representa um vertice do grafo.
    bool tentou = true;
	list<int> lista;
	list<int>::iterator it;
    
    lista.push_back(inicio); // Enfileira a raiz.
    // Enquanto tentou não for falso.
    while(tentou){
    	if(lista.empty()) return true;
        int u = lista.front(); // Define u como sendo o vértice na frente na fila;
        tentado[u] = true;

        if(aberto[u]){
        	if(cor[u] == CINZA && cor[u] == AZUL) cor[u] == PRETO;
        	for(int i = 1; i < aberto.size(); i++){
        		if(matriz[u][i]){
        		 aberto[i] = true;
        		 if(cor[u] != AZUL) cor[i] = CINZA;
        		}
        	}
    	}
    	// todos tentados e não abertos encerra, senão continua;
    	tentou = TNA(lista);
    
    	// tentado e não aberto insere na fila;
    	if(!aberto[u]){
    		lista.push_back(u); 
    	}else{
	        for(int i = 0; i < g[u].size(); i++){
	        	if(cor[g[u][i]] != PRETO && cor[g[u][i]] != AZUL ){
				cor[g[u][i]] = AZUL; lista.push_back(g[u][i]);
				} // Enfileira o vertice adjacente.
	        }
	    }
	//cout << "corrente -> " << u << endl << endl;
	lista.pop_front();
    }
    // *** OBS: O RETORNO DA FUNÇÃO PODE SER ALTERADO CONFORME A NECESSIDADE DO PROBLEMA. ***
    return false; 
}

int main(){
	int N, M, chave;
	while(cin >> N){
		cin >> M;
		int x,y;
		matriz.resize(N+1);
		g.resize(N+1);
		aberto.resize(N+1,false);
		tentado.resize(N+1,false);
		cor.resize(N+1, BRANCO);
		aberto[1] = true;
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= N; j++)
				matriz[i].push_back(false);
		
		for(int i=0;i<M;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
		for(int sala = 2; sala <= N; sala++){
			cin >> chave;
			matriz[chave][sala] = true;
		}
		
		bool abriu = bfs(1);
		for(int i=1;i<=N;i++){ 
		if(cor[i] == BRANCO) abriu = false;
		}
		if(abriu) cout << "sim" << endl;
		else cout << "nao" << endl;
		g.clear();
		matriz.clear();
		aberto.clear();
		tentado.clear();
		cor.clear();

	}
    return 0;
}
