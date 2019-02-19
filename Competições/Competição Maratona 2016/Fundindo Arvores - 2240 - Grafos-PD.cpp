#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
using namespace std;

int *local1, *local2;
vector<int> *a1;
vector<int> *a2;
vector< vector< vector<int> > > g; // Lista de Adjacência

void bfs(int inicio,  int op, int* raiz_a1, int* raiz_a2, int* sdc_a1, int* sdc_a2){
    vector<int> d(g[op].size(), 0);
    vector<int> p(g[op].size(), -1); 
	queue<int> Q;
	
    d[inicio] = 0;
    Q.push(inicio); 
	p[1] = 1;
	int pai;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        pai = u;
        for(int i = 0; i < g[op][u].size(); i++){
            Q.push(g[op][u][i]);
	        p[g[op][u][i]] = pai;
            if(!op){
                if(local1[g[op][u][i]]){
           			d[g[op][u][i]] = d[u]+1;
           		//	printf("dist do adj = %d\n", d[g[op][u][i]]);
           			if(d[g[op][u][i]] > *sdc_a1)
						*sdc_a1 = d[g[op][u][i]];
				}
               // printf("u = %d / p[u] = %d / adj = %d / local do adj = %d\n", u, p[u], g[op][u][i], local1[g[op][u][i]]);
	            if(p[u] == 1 && local1[g[op][u][i]] && local1[u]){
				    (*raiz_a1)++;
				    //printf("raiz - %d\n", *raiz_a1);
                    p[g[op][u][i]] = 1;
				}else{
					p[g[op][u][i]] = u;
				}
			}else{
                if(local2[g[op][u][i]]){
           			d[g[op][u][i]] = d[u]+1;
           		//	printf("dist do adj = %d\n", d[g[op][u][i]]);
           			if(d[g[op][u][i]] > *sdc_a2)
						*sdc_a2 = d[g[op][u][i]];
				}
	           // printf("u = %d / p[u] = %d / adj = %d / local do adj = %d\n", u, p[u], g[op][u][i], local2[g[op][u][i]]);
	            if(p[u] == 1 && local2[g[op][u][i]]  && local2[u]){
		       		//printf(" u = %d / pai do u = %d / local do u = %d\n", u, p[u], local2[u]);
				    (*raiz_a2)++;
				   // printf("raiz - %d\n", *raiz_a2);
                    p[g[op][u][i]] = 1;
				}else{
					p[g[op][u][i]] = u;
				}
			}
		}
    }
}
// 0 arvore da esquerda, 1 arvore da direita
int main(){
	int n1, n2, i, x, y, id;
	int raiz_a1 = 1, raiz_a2 = 1, sdc_a1 = 1, sdc_a2 = 1;
	cin >> n1;
	local1 = new int[n1+1];
    local1[1] = 1;
    g.resize(3);
    g[0].resize(n1+1);
	for(i = 1; i <= n1; i++){
		cin >> id >> x >> y;
		if(x){ g[0][id].push_back(x);
			local1[x] = 0;
		}
		if(y){ g[0][id].push_back(y);
		    local1[y] = 1;
		}
	}
	cin >> n2;
	local2 = new int[n2+1];
    g[1].resize(n2+1);
    local2[1] = 1;
	for(i = 1; i <= n2; i++){
		cin >> id >> x >> y;
		if(x){ g[1][id].push_back(x);
			local2[x] = 1;
		}
		if(y){ g[1][id].push_back(y);
			local2[y] = 0;
		}
	}
	bfs(1, 0, &raiz_a1, &raiz_a2, &sdc_a1, &sdc_a2);
	//puts("_______________________________________________________");
	bfs(1, 1, &raiz_a1, &raiz_a2, &sdc_a1, &sdc_a2);
	//printf("raiz_a1 = %d / raiz_a2 = %d\n", raiz_a1, raiz_a2);
	//printf("sdc_a1 = %d / sdc_a2 = %d\n", (++sdc_a1), (++sdc_a2));
	int vert_sup = max(min(raiz_a1, (++sdc_a2)), min(raiz_a2, (++sdc_a1)));
	printf("%d\n", (n1+n2) - vert_sup);
	system("PAUSE");
    return 0;
}
