#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector< vector<int> > g;
vector<bool> cor;

int bfs(int inicio){
	int cont = 0;
	queue<int> Q; 
    cor[inicio] = true; 
    Q.push(inicio); 

    while(!Q.empty()){
        int u = Q.front();
        Q.pop(); 
        for(int i = 0; i < g[u].size(); i++){
			if(cor[g[u][i]] == false){
                Q.push(g[u][i]); 
                cor[g[u][i]] = true;
            }
        }
		cont++;
    }
	if(!cont) return 1;
    return (cont);// foi tirado o +1 daqui
}

int main(){
	int H, L, i, j;
	int lad[201][201];
	cin >> H >> L;
	g.resize(H*L+1);
	
	//recebendo os valores
	for(i = 1; i <= H; i++)
		for(j = 1; j <= L; j++)
			cin >> lad[i][j];
			
	//identificando conexões e criando os grafos
	int hor = 0, vert;
	for(i = 1; i <= H; i++){
		vert = i*L;
	    for(j = 1; j <= L; j++){
			if(j < L){
				if(lad[i][j] == lad[i][j+1]){
					g[hor+j].push_back(hor+j+1);
					g[hor+j+1].push_back(hor+j);
					//printf("%d - %d / num: %d\n", hor+j, hor+j+1, lad[i][j]);
				}
			}
			if(i < H){
				if(lad[i][j] == lad[i+1][j]){
					//printf("lad -> %d\n", lad[i+1][j]);
	                g[hor+j].push_back(vert+j);
					g[vert+j].push_back(hor+j);
					//printf("%d - %d / num: %d\n", hor+j, vert+j, lad[i][j]);
				}
			}
		}
		hor = vert;
	}
	set<int> tam;
	cor.resize(g.size());
	for(i = 1; i < H*L; i++){
		if(cor[i] == false){
			//printf("-------- bfs -> %d ------------\n", i);
			tam.insert(bfs(i));
		}
	}
	printf("%d\n", *tam.begin());
	
	system("PAUSE");

    return 0;
}
