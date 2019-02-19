#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <algorithm>
#include <set>

#define INF -1 // N?o descoberto (desconexo).
#define NUL -2 // Orf?o (raiz).
#define PRETO 0 // Descendentes j? est?o pretos ou n?o tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // N?o descoberto.

int *cor;
int *predescessor;
int *local1, *local2;
int sdcraiz_a1, sdcraiz_a2;

using namespace std;

vector<int> *a1;
vector<int> *a2;

set<int> dir;
set<int> esq;
set<int>::iterator it_set, it_a1, it_a2;

//ACHANDO A SDC DA RAIZ
int sdc_raiz(int op, int raiz){
    local1[0] = 0;
    local2[0] = 0;
	int cont = 1;
	bool aux = true;
	int vA = raiz;
	vector<int>::iterator it;
	if(!op){
		while(aux){
		    for(it = a1[vA].begin(); it != a1[vA].end(); it++){
                //printf("local1[%d] = %d / it = %d\n", *it, local1[*it], *it);
				if(local1[*it] && *it){
					cont++;
					//printf("vA = %d / it = %d / local1 = %d / a1[vA][0] = %d / a1[vA][1] = %d\n",
					//vA, *it, local1[*it], a1[vA][0], a1[vA][1]);
					vA = *it;
					aux = true;
					break;
				}else if(!local1[*it]){
					aux = false;
				}
			}
			
		}
	}else{
        while(aux){
		    for(it = a2[vA].begin(); it != a2[vA].end(); it++){
				//printf("local2[%d] = %d / it = %d\n", *it, local2[*it], *it);
				if(local2[*it] && *it){
					cont++;
					//printf("vA = %d / it = %d / local2 = %d / a2[vA][0] = %d / a2[vA][1] = %d\n",
					//
					vA, *it, local2[*it], a2[vA][0], a2[vA][1]);
					vA = *it;
					aux = true;
					break;
				}else if(!local2[*it]){
					aux = false;
				}
			}
		}
	}
	return cont;
}

//BUSCANDO TODAS AS SDC'S DA ARVORE
void DFS_visit_a1(int vA, int* cont, int raiz){
     int vB;
     local1[0] = 0;
     vector<int>::iterator it;
     if(vA) cor[vA] = CINZA;
     for(it = a1[vA].begin(); it != a1[vA].end(); it++){
		 vB = *it;
		// printf("fase1 - vB = %d / cor[vB] = %d / local1[vB] = %d / cont = %d\n", vB, cor[vB], local1[vB], *cont);
         if(cor[vB] == BRANCO){
             predescessor[vB] = vA;
            // printf("fase2 - vB = %d / vA = %d / cor[vB] = %d / local1[vB] = %d / cont = %d\n", vB, vA, cor[vB], local1[vB], *cont);
             if(local1[vB]){ (*cont)++;
             // printf("fase3 - vB = %d / vA = %d / cor[vB] = %d / local1[vB] = %d / cont = %d\n", vB, vA, cor[vB], local1[vB], *cont);
			 }
			 else{ esq.insert(*cont);
		     *cont = 1;
			 // printf("fase4 - vB = %d / vA = %d / cor[vB] = %d / local1[vB] = %d / cont = %d\n", vB, vA, cor[vB], local1[vB], *cont);}
		 	 }
		 }
         DFS_visit_a1(vB, cont, raiz);
	}
	if(vA) cor[vA] = PRETO;
}

void DFS_visit_a2(int vA, int* cont, int raiz){
     int vB;
     local2[0] = 0;
     vector<int>::iterator it;
     if(vA) cor[vA] = CINZA;
     for(it = a2[vA].begin(); it != a2[vA].end(); it++){
		 vB = *it; 
         if(cor[vB] == BRANCO){
             predescessor[vB] = vA;
             if(local2[vB]) (*cont)++;
			 else{ dir.insert(*cont);
		     *cont = 1;}
		 }
         DFS_visit_a2(vB, cont, raiz); 
	 }
     if(vA) cor[vA] = PRETO;
}

void DFS(int numeroDeVertices, int raiz, int op){
    // Aloca??o din?mica
    cor = new int[numeroDeVertices];
    predescessor = new int[numeroDeVertices];
	int cont = 1;
    int vA;
    cor[0] = BRANCO;
    for(vA = 1; vA < numeroDeVertices; vA++) // Coloca os valores iniciais em todas as posi??es dos vetores cor, descoberta e predecessor.
    {
        cor[vA] = BRANCO;
        predescessor[vA] = NUL;
	}
	if(!op){
        // puts("_______________________________________________________________");
		for(int i = 1; i < numeroDeVertices; i++){
			if(cor[i]==BRANCO)
				DFS_visit_a1(raiz, &cont, raiz);
		}
        if(cont > 0) esq.insert(cont);
	}else{
        // puts("_______________________________________________________________");
		for(int i = 1; i < numeroDeVertices; i++){
			if(cor[i]==BRANCO)
		    	DFS_visit_a2(raiz, &cont, raiz);
		}
        if(cont > 0) dir.insert(cont);
	}
}

int main(){
	int n1, n2, i, x, y, id, cont;
	int *e, *d, *e1, *d1;
	
	cin >> n1;
	local1 = new int[n1+1];
    a1 = new vector<int> [n1+1];
    
    local1[1] = 1;
	for(i = 1; i <= n1; i++){
		cin >> id >> x >> y;
		a1[id].push_back(x);
		local1[x] = 0;
		a1[id].push_back(y);
		local1[y] = 1;
	}
	
	cin >> n2;
	local2 = new int[n2+1];
    a2 = new vector<int> [n2+1];
    local2[1] = 1;
	for(i = 1; i <= n2; i++){
		cin >> id >> x >> y;
		a2[id].push_back(x);
		local2[x] = 1;
		a2[id].push_back(y);
		local2[y] = 0;
	}
	
	DFS(n1+1, 1, 0); // 0 para rodar a arvore canhota
	it_a1 = esq.end();
	printf("sdc max a1 = %d\n", *(--it_a1));
	DFS(n2+1, 1, 1); // 1 para rodar a arvore destra
	it_a2 = dir.end();
	printf("sdc max a2 = %d\n", *(--it_a2));
	puts("");
	for(it_set = esq.begin(); it_set != esq.end(); it_set++){
		printf("esq.set -> %d\n", *it_set);
	}
	for(it_set = dir.begin(); it_set != dir.end(); it_set++){
		printf("dir.set -> %d\n", *it_set);
	}
    puts("_______________________________________________________________");
	sdcraiz_a1 = sdc_raiz(0, 1);
	printf("sdcraiz_a1 = %d\n", sdcraiz_a1);
	puts("_________________________________________________________");
	sdcraiz_a2 = sdc_raiz(1, 1);
	printf("sdcraiz_a2 = %d\n", sdcraiz_a2);
	

	//printf("sdc_a1 max -> %d / sdc_a2 max -> %d\n", *(--it_a1), *(--it_a2));
	system("PAUSE");
    return 0;
}
