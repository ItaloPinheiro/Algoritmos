#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>

using namespace std;

int bfs(int inicio, int N, vector< vector<int> > g, vector< vector<int> > c);

int main(){
	int N,M;
	while((cin>>N>>M) && N){		
		int x,y,chave;
		vector< vector<int> > g; // Lista de Adjacência
		vector< vector<int> > c;
		for (int i = 0; i <= N; i++){
   			g.push_back( vector<int>());// Create an empty row
    	}
    	for (int i = 0; i <= N; i++){
   			c.push_back( vector<int>());// Create an empty row
    	}
		
		for(int i=0;i<M;i++)
		{
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		bfs(1, N, g, c); //passa o vetor "inicio" com o número digitado 
	}
	return 0;
}

int bfs(int inicio, int N, vector< vector<int> > g, vector< vector<int> > c){
	int chave;
	for(int i=2; i<=N; i++){
		cin>>chave;
		
		c[chave].push_back(i);
	}a
	//para os 3 vetores a seguir, cada posição do vetor representa um vertice do grafo.
    vector<int> cor(N+1, 0); // Define se cada vertice ja foi encontrado ou não.
	queue<int> Q; // Fila que define a ordem de acesso aos vertices.
	// Inicialização: cor BRANCO = 0; CINZA = 2; CHAVEDAPORTA = 1; PRETO = 3;
	
    cor[inicio] = 3; // Define a cor do vértice raiz como acessado.
    Q.push(inicio); // Enfileira a raiz.
    int tna=0;
    // Enquanto a fila não estiver vazia.
    while(!Q.empty()){
        int u = Q.front(); // Define u como sendo o vértice na frente na fila.
		Q.pop();		
		   
        for(int i = 0; i < g[u].size(); i++){
           if(cor[g[u][i]] == 0 && cor[g[u][i]] != 2){
                 // Enfileira o vertice adjacente.
                cor[g[u][i]] = 1; // Define o vertice adjacente como encontrado.
            }
            else if(cor[g[u][i]] == 2){
            	cor[g[u][i]] = 3;
            	Q.push(g[u][i]);
            	
            }
	        
	    }
	    for(int i = 0; i < c[u].size(); i++){
           if(cor[c[u][i]] == 0 && cor[c[u][i]] != 1){
                //Q.push(g[u][i]); // Enfileira o vertice adjacente.
                cor[c[u][i]] = 2; // Define o vertice adjacente como encontrado.
            }
            else if(cor[c[u][i]] == 1) {
            	cor[c[u][i]] = 3;
            	Q.push(c[u][i]);
            }
	    }
	}
	for(int i = 1; i <= N; i++){
		if(cor[i] != 3){
			cout<<"nao"<<endl;
			return 0;
		}
	}
	cout << "sim" << endl;
	return 0;
}
