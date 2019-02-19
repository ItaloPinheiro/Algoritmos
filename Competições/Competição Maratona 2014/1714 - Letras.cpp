#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > g;

void convert(int* letra, int num){
	int i = 0;
	while(num > 1){
		letra[i] = num%2;
		num /= 2;
		i++;
	}
	letra[i] = num;
}

int bfs(int inicio, int* letra, char* p_aux){
	int cont = 0, entra = 0;
	queue<int> Q;
	vector<int> cor(g.size(), 0);
	vector<int> d(g.size(), -1);
	d[inicio] = 0;
	cor[g.size()-1] = 2;
    cor[inicio] = 1;
	//printf("letra inicial -> %c\n", p_aux[inicio]);
    if(p_aux[inicio] < 'a'){
		if(letra[p_aux[inicio] - 'A']){
            Q.push(inicio);
		}
	}else{
    	if(!(letra[p_aux[inicio] - 'a'])){
	        Q.push(inicio);
		}
	}

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

       // printf("rodando u -> %d\n", u);
        for(int i = 0; i < g[u].size(); i++){
		//	printf("g[u][i] - > %d\n", g[u][i]);
			if(cor[g[u][i]] == 2){
                if(p_aux[g[u][i]] < 'a'){
					if(letra[p_aux[g[u][i]] - 'A']){
            			return (d[u] + 2);
					}else return -1;
				}else{
	    			if(!(letra[p_aux[g[u][i]] - 'a'])){
		        		return (d[u] + 2);
					}else return -1;
				}
			//	printf("dist -> %d\n", d[g[u][i]]);
				
			}
			//printf("letra -> %c\n", p_aux[g[u][i]]);
            if(p_aux[g[u][i]] < 'a'){
				if(letra[p_aux[g[u][i]] - 'A']){
                    if(cor[g[u][i]] == 0){
	                	Q.push(g[u][i]);
	                	cor[g[u][i]] = 1;
	                	d[g[u][i]] = d[u]+1; 
	            	}
				}
			}else{
                if(!(letra[p_aux[g[u][i]] - 'a'])){
                    if(cor[g[u][i]] == 0){
	                	Q.push(g[u][i]);
	                	cor[g[u][i]] = 1;
	                	d[g[u][i]] = d[u]+1;
	            	}
				}
			}
	    }
	    //printf("Frente da fila -> %d\n", Q.front());
	   // puts("");
    }
    return -1;
}

int main(){
	int i, j, k, n, aux = 0;
	int max, max_valor = 10001;
	scanf("%d", &n);
	g.resize(n*n+1);
	string p[n+1];
	char p_aux[n*n+1];
	int letra[11] = {};
	
	for(i = 0; i < n; i++)
		cin >> p[i];
		
	int hor = 0, vert;
	for(i = 1; i <= n ; i++){
		vert = i*n;
		for(j = 1; j <= n; j++){
			p_aux[aux+j] = p[i-1][j-1];
			if(j < n){
				g[hor+j].push_back(hor+j+1);
				g[hor+j+1].push_back(hor+j);
				//printf("%d com %d\n", hor+j, hor+j+1);
			}
			if(i < n){
		        g[hor+j].push_back(vert+j);
				g[vert+j].push_back(hor+j);
				//printf("%d com %d\n", hor+j, vert+j);
			}
		}
		aux += n;
		hor = vert;
	}
	//puts("");
	/*
	for(i = 1; i < n*n+1; i++){
		printf("%c", p_aux[i]);
		if(!(i % n)) puts("");
	}
	*/
	
	for(i = 1; i <= 1024; i++){
		convert(letra, i);
		//for(j = 0;  j < 10; j++) printf("%d ", letra[j]);
		//puts("");
		max = bfs(1, letra, p_aux);
 		//printf("max -> %d\n", max);
		if(max_valor > max && max != -1) max_valor = max;
		//system("pause");
	}
	if(max_valor == 10001) puts("-1");
	else printf("%d\n", max_valor);
	system("pause");
	return 0;
}
