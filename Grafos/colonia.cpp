#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <math.h>
 
 
#define INF -1 // N?o descoberto (desconexo).
#define NUL -2 // Orf?o (raiz).
#define PRETO 0 // Descendentes j? est?o pretos ou n?o tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // N?o descoberto.

using namespace std;

vector< vector<long> > ancestral;
vector< vector<long long> >peso;
vector<int> pai;
vector<int> nivel;
long long pesoFinal;

vector< vector<int> > g;

int LCA(int u, int v, int N){
    
    if(nivel[u] < nivel[v]) swap(u, v); // isto é para definir u como estando mais abaixo
    
    // vamos agora fazer nivel[u] ser
    // igual nivel[v], subindo pelos
    // ancestrais de u
    
    for(int i = N-1;i >= 0;i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];
            
    // agora, u e v estão no mesmo nível
    if(u == v) return u;
    
    // subimos o máximo possível de forma
    // que os dois NÃO passem a ser iguais
    
    for(int i = N-1;i >= 0;i--)
        if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    
    // como subimos o máximo possível
    // sabemos que u != v e que pai[u] == pai[v]
    // logo, LCA(u, v) == pai[u] == pai[v]
    
    return pai[u];
}

// Algoritmo calcula a menor distancia para alcançar todos os vertices do grafo partindo de um vertice inicial.
void dfs(int u){
    
    for(int i = 0;i < (int)g[u].size();i++){
        int v = g[u][i];
        
        if(nivel[v] == -1){
            pai[v] = u;
            nivel[v] = nivel[u]+1;
            
            dfs(v);
        }
    }
    
}

int main(){
	long N;
	long long resultado = 0LL;
	while(cin >> N){
		ancestral.resize(N+1);
		g.resize(N+1);
		pai.resize(N+1, -1);
		nivel.resize(N+1, -1);
		peso.resize(N+1);
		for(int i = 0; i <= N; i++){
			ancestral[i].resize(N+1, -1);
			peso[i].resize(N+1, 0);
		}
		for(int i = 1; i < N ;i++){
		    int a = i, b, p;
		    cin >> b >> p;
		    peso[a][b] = p;
		    peso[b][a] = p;
		    // montar a lista
		    g[a].push_back(b);
		    g[b].push_back(a);
		    cout << "no for" << endl;
		}
		cout << "saiu" << endl;
		nivel[0] = 0;
		dfs(0);
		for(int i = 0; i < N; i++) cout << i << " - " << pai[i] << endl;
				
		for(int i = 0; i <= N; i++) ancestral[i][0] = pai[i];
		
		for(int j = 1; j < N; j++)
			for(int i = 0; i <= N; i++)
    			if(ancestral[i][j-1] != -1){
        			ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
        			cout << "-> i = " << i << " / j = " << j << " <= " << ancestral[ ancestral[i][j-1] ][j-1] << endl;
        		}
        			
    	cout << "saiu" << endl;
        			
		int casos, v1, v2;
		cin >> casos;
		while(casos--){
			cin >> v1 >> v2;
			resultado += (long long)( nivel[v1] + nivel[v2] - 2*nivel[ LCA(v1, v2, N) ]);
			cout <<  resultado << endl;
		}
    }
    return 0;
}
