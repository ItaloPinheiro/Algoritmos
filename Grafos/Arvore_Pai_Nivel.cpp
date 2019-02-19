#include <iostream>
#include <stdio.h>
using namespace std;

//Montagem de uma árvore
int *pai;
int *nivel;

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

int main(){
	int N, v1, v2;
	int i, j;
	scanf("%d", &N);
	tree.resize(N+1);
	pai = new int[N+1];
	nivel = new int[N+1];
	for(i = 1; i <= N-1; i++){
		scanf("%d %d", v1, v2);
		tree[v1].push_back(v2);
	}
	monta_arvore(1, 1, 0);
}
