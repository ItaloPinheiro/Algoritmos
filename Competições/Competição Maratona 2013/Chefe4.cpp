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
#define MAX 501

int *cor;
int *predescessor;

using namespace std;
vector< vector<int> >g;
int final;

class Vertice{
	public:
	int ind;
	int idade;
};

vector<Vertice> vet;

void DFS_visit(int vA, int* idade)
{
    int vB;
    vector<int>::iterator it;
    cor[vA] = CINZA; // Pinta de cinza o v?rtice que est? sendo avaliado no momento, o que significa que ele acaba de ser descoberto.
    for(it = g[vet[vA].ind].begin(); it != g[vet[vA].ind].end(); it++) // Varre o vector, passando por todos os v?rtices adjacentes ao v?rtice u.
    {
        vB = *it; // Recebe o valor para que o iterador est? apontando
        //printf("vB -> %d / vet[vB].ind -> %d/ idade -> %d\n", vB, vet[vB].ind, idade[vet[vB].ind]);
        if(final > idade[vet[vB].ind]) final = idade[vet[vB].ind];
		
        if(cor[vB] == BRANCO) // Se o v?rtice(vB) adjacente ?quele que est? sendo avaliado(vA) ainda n?o tiver sido descoberto (branco).
		{
			//printf("vB - %d/ vA - %d\n", vB, vA);			
            DFS_visit(vB, idade); // A fun??o ? chamada, recursivamente, para avaliar o v?rtice adjacente.
        }
    }
    

    cor[vA] = PRETO; // Pinta de preto o v?rtice que est? sendo avaliado pela fun??o, j? que todos os v?rtices descendentes dele j? foram completamente avaliados (e tamb?m pintados de preto).
}


void DFS(int numeroDeVertices, int raiz, int* idade){
    // Aloca??o din?mica
    cor = new int[numeroDeVertices];
    predescessor = new int[numeroDeVertices];
    int vA, i;

    for(vA = 0; vA < numeroDeVertices; vA++) // Coloca os valores iniciais em todas as posi??es dos vetores cor, descoberta e predecessor.
        cor[vA] = BRANCO;
        
    DFS_visit(raiz, idade); // Chama uma segunda fun??o, que ser? utilizada recursivamente, enviando o v?rtice raiz como par?metro

}


int main()
{
	int N, M, I;
	int i, j, k, x, y, aux;
	char op;
	scanf("%d %d %d", &N, &M, &I);
	vector<Vertice>::iterator it, it_aux;
    g.resize(N+1);
    vet.resize(N+1);
	int idade[N+1];
			
	for(i = 1; i <= N; i++){
		scanf("%d", idade+i);
		Vertice v;
		v.ind = i;
		v.idade = idade[i];
		vet[i] = v;
	}
	
	
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
			for(it = vet.begin(); it != vet.end(); it++){
				if(it->ind == x){
					it_aux = it;
					it->idade = idade[y];
					break;
				}
			}
			for(it = vet.begin(); it != vet.end(); it++){
				if(it->ind == y){
					it_aux->ind = y;
					it->ind = x;
					it->idade = idade[x];
					break;
				}
			}
			puts("troca feita");
			getchar();
		}else{
			scanf("%d", &x);
			DFS(N+1, x, idade);
			getchar();
			if(final != 101)
				printf("final -> %d\n", final);
			else puts("*");
		}

	}
	system("PAUSE");
    return 0;
}
