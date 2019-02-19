#include <iostream>
#include <stdio.h>
using namespace std;

//Montagem de uma árvore
int *pai;
int *nivel;
int *super_pai;
vector< vector<int> > tree;
void monta_arvore(int u, int p, int l) {
    pai[u] = p;
    nivel[u] = l;

    for(int i=0; i<(int)tree[u].size(); i++) {
        int v = adj[u][i];

        if(!pai[v]) {
            monta_arvore(v, u, l+1);
        }
    }
}

//LCA com super-pai: otimização
void monta_super_pai(int u, int p) {
    super_pai[u] = p;

    if(nivel[u] % segmento == 0){
        p = u;
    }

    for(int i=0; i<(int)adj[u].size(); i++) {
        int v = adj[u][i];

        if(!super_pai[v]) {
            monta_super_pai(v, p);
        }
    }
}

int lca(int a, int b) {
    while(super_pai[a] != super_pai[b]) {
        if(nivel[a] > nivel[b]) {
            a = super_pai[a];
        } else {
            b = super_pai[b];
        }
    }
    while(a != b) {
        if(nivel[a] > nivel[b]) {
            a = pai[a];
        } else {
            b = pai[b];
        }
    }
    return a;
}

int main(){
	int N, v1, v2;
	int i, j;
	scanf("%d", &N);
	tree.resize(N+1);
	pai = new int[N+1];
	nivel = new int[N+1];
	super_pai = new int[N+1];
	for(i = 1; i <= N-1; i++){
		scanf("%d %d", &v1, &v2);
		tree[v1].push_back(v2);
	}
	monta_arvore(1, 1, 0);
	monta_super_pai(1, 1);
	scanf("%d %d", &v1, &v2);
	int n_lca = lca(v1, v2);
	printf("lca de %d e %d é %d\n", v1, v2, n_lca);
}
