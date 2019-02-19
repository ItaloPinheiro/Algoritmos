#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <algorithm>
 
#define PRETO 0 // Descendentes j? est?o pretos ou n?o tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // N?o descoberto.
 
 
int *cor;
int count_cicles;
using namespace std; 
 
vector< vector<int> > g;
vector< vector<int> > gt;
stack<int> pilha;

void clear(){
	while(!pilha.empty())
		pilha.pop();
}

//DFS - depth first search - Grafo transposto
void DFS_GT(int v){
	// marca o vértice atual como visitado
	cor[v] = BRANCO;

	// imprime o vértice
	//printf("%d ", v);
	
	//conta o tamanho do ciclo
	count_cicles++;

	// percorre os adjacentes de v
	vector<int>::iterator it;
	for(it = gt[v].begin(); it != gt[v].end(); it++)
		if(cor[*it] == BRANCO)
			DFS_GT(*it);
			
}

void preenche(int v){
	// marca o vértice atual como visitado
	cor[v] = PRETO;

	// percorre os adjacentes de v
	vector<int>::iterator it;
	for(it = g[v].begin(); it != g[v].end(); it++)
		if(cor[*it] == BRANCO)
			preenche(*it);
			
	pilha.push(v);
}

bool Kosarajus(int V){
	int i;
	cor = new int[V+1];
	for(i = 1; i <= V; i++)
		cor[i] = BRANCO;
		
	for(i = 1; i <= V; i++)
		if(cor[i] == BRANCO)
			preenche(i);
			
	for(i = 1; i <= V; i++)
		cor[i] = BRANCO;

	while(!pilha.empty()){
		count_cicles = 0;
		int v = pilha.top();
		pilha.pop();
		if(cor[v] == BRANCO){
			DFS_GT(v);
			//puts("");
		}
		if(count_cicles == V) return true;
	}
	delete cor;
	return false;
}

int main(){
	int N, M;
	while(scanf("%d %d", &N, &M) && N != 0){
	    g.resize(N+1);
	    gt.resize(N+1);
	    vector<int>::iterator it;
	    int i, x, y, doublelig;
	    //formando grafo normal
		for(i = 0; i < M; i++){
			scanf("%d %d %d", &x, &y, &doublelig);
			g[x].push_back(y);
			if(doublelig == 2)
				g[y].push_back(x);
		}
		
		//formando grafo transposto
		for(i = 1; i <= N; i++)
			for(it = g[i].begin(); it != g[i].end(); it++)
				gt[*it].push_back(i);
				
		bool connected = Kosarajus(N);
		if(connected) puts("1");
		else puts("0");
		clear();
	}
    return 0;
}
