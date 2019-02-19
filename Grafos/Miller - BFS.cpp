#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>

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
	int N,M;
	cin>>N>>M;
	int x,y;
	g.resize(N+1);
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> dist = bfs(3);
	for(int i=1;i<=N;i++)
	{
		cout<<i<<" "<<dist[i]<<endl;
	}
	system("PAUSE");
	
    return 0;
}
