#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

#define PRETO 0
#define CINZA 1 
#define BRANCO 2 

//Montagem de uma árvore
int *cor;
int *pai;
int *nivel;
int *super_pai;
vector< vector<int> > tree;

//segmento = raiz(nivel_max)
int nivel_max;
int segmento;

void monta_arvore(int u, int p, int l);

void monta_super_pai(int u, int p);

int lca(int a, int b);

int main(){
	int N, n1, n2, vi, v1, v2;
	int i, j;
	while (scanf("%d %d %d %d", &N, &vi, &v1, &v2) != EOF){
	
		tree.resize(N+1);
		cor = new int[N+1];
		pai = new int[N+1];
		nivel = new int[N+1];
		super_pai = new int[N+1];
		nivel_max = 0;
		
		for(i = 0; i <= N; i++){
			cor[i] = BRANCO;
			pai[i] = 0;
			nivel[i] = 0;
			super_pai[i] = 0;
		}
		
		for(i = 1; i < N; i++){
			scanf("%d %d", &n1, &n2);
			tree[n1].push_back(n2);
			tree[n2].push_back(n1);
		}
		
		monta_arvore(vi, vi, 0);
		segmento = sqrt(nivel_max);
		//printf("nivel: %d / seg: %d\n", nivel_max, segmento);
		monta_super_pai(vi, vi);
		int n_lca = lca(v1, v2);
		cout << n_lca << endl;
		//if(n_lca == v1) n_lca = vi;
		//printf("lca de %d e %d: %d\n", v1, v2, n_lca);
		int qtd_arestas = abs(nivel[v1] - nivel[n_lca]) + abs(nivel[v2] - nivel[n_lca]);
		//printf("qtd_arestas: %d\n", qtd_arestas);
		float prob = (float) (qtd_arestas - abs(nivel[v1] - nivel[n_lca])) / qtd_arestas;
		printf("%.6f\n", prob);	
		tree.clear();
	}
}

void monta_arvore(int u, int p, int l){
    pai[u] = p;
    nivel[u] = l;
    
    if(l > nivel_max)
 		nivel_max = l;
 		
	cor[u] = CINZA;
    for(int i = 0; i < tree[u].size(); i++){
    	int v = tree[u][i];
    	if(cor[v] == BRANCO){
			//printf("u = %d / v = %d\n", u, v);
	        if(!pai[v])
	            monta_arvore(v, u, l+1);
	    }
    }
    
    cor[u] = PRETO;
}

//LCA com super-pai: otimização
void monta_super_pai(int u, int p){
    super_pai[u] = p;

    if(nivel[u] % segmento == 0)
        p = u;
    
	
    for(int i = 0; i < tree[u].size(); i++){
    	
        int v = tree[u][i];
		
        if(!super_pai[v]) 
        	monta_super_pai(v, p);
        
    }
}

int lca(int a, int b){
	while(super_pai[a] != super_pai[b]){
		
		if(nivel[a] > nivel[b])
			a = super_pai[a];
		else 
			b = super_pai[b];
		
	}
	
	while(a != b){
		//printf("a = %d / b = %d\n", a, b);
		//printf("nivel a = %d / nivel b = %d\n", nivel[a], nivel[b]);
		if(nivel[a] > nivel[b]) 
			a = pai[a];
		else 
			b = pai[b];
		//system("pause");
	}
	
	return a;
}

