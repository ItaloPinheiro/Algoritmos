#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string.h>


#define INF -1 // N?o descoberto (desconexo).
#define NUL -2 // Orf?o (raiz).
#define PRETO 0 // Descendentes j? est?o pretos ou n?o tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // N?o descoberto.

int *cor;
int *predescessor;

using namespace std;

vector< vector<int> > g;
int final;

void DFS_visit(int vA, int* idade)
{
     int vB;
     vector<int>::iterator it;
     cor[vA] = CINZA; // Pinta de cinza o v?rtice que est? sendo avaliado no momento, o que significa que ele acaba de ser descoberto.

     for(it = g[vA].begin(); it != g[vA].end(); it++) // Varre o vector, passando por todos os v?rtices adjacentes ao v?rtice u.
     {
         vB = *it; // Recebe o valor para que o iterador est? apontando
         if(cor[vB] == BRANCO) // Se o v?rtice(vB) adjacente ?quele que est? sendo avaliado(vA) ainda n?o tiver sido descoberto (branco).
		 {
			 //printf("final -> %d / idade[%d] -> %d\n", final, vB, idade[vB]);
			 if(idade[vB] < final) final = idade[vB];
             DFS_visit(vB, idade); // A fun??o ? chamada, recursivamente, para avaliar o v?rtice adjacente.
         }
     }

     cor[vA] = PRETO; // Pinta de preto o v?rtice que est? sendo avaliado pela fun??o, j? que todos os v?rtices descendentes dele j? foram completamente avaliados (e tamb?m pintados de preto).
}


void DFS(int numeroDeVertices, int raiz, int* idade)
{
	if(!g[raiz].size()){
		final = 0;
		return;
	}
    // Aloca??o din?mica
    cor = new int[numeroDeVertices];
    predescessor = new int[numeroDeVertices];
    int vA, i;

    for(vA = 0; vA < numeroDeVertices; vA++) // Coloca os valores iniciais em todas as posi??es dos vetores cor, descoberta e predecessor.
        cor[vA] = BRANCO;

    for(i = 1; i <= numeroDeVertices; i++){
		if(cor[i] == BRANCO){
    		DFS_visit(raiz, idade); // Chama uma segunda fun??o, que ser? utilizada recursivamente, enviando o v?rtice raiz como par?metro.
		}
	}

}


int main()
{
	int N, M, I;
	int i, x, y, aux;
	char op;
	scanf("%d %d %d", &N, &M, &I);
	vector<int>::iterator it;
    g.resize(N+1);
	int idade[N+1];
	for(i = 1; i <= N; i++)
		scanf("%d", idade+i);

	for(i = 0; i < M; i++){
		scanf("%d %d", &x, &y);
		g[y].push_back(x);
	}
	getchar();
	for(i = 0; i < I; i++){
		final = 101;
		scanf("%c", &op);
        getchar();
		if(op == 'T'){
			scanf("%d %d", &x, &y);
			g[x].swap(g[y]);
			aux = idade[x];
			idade[x] = idade[y];
			idade[y] = aux;
			puts("troca feita");
			getchar();
		}else{
			scanf("%d", &x);
            DFS(N+1, x, idade);
            if(final)
            	printf("%d\n", final);
			else puts("*");
			getchar();
		}
		
	}
	system("PAUSE");
    return 0;
}
