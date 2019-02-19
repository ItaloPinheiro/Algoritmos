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

using namespace std;

class Vertice{
	public:
	int ind;
	int idade;
};

vector< vector<int> >g;
vector<Vertice> vet;
vector<Vertice> fixo;
int final;

void DFS_visit(int vA)
{
    int vB;
    vector<int>::iterator it;
    cor[vA] = CINZA; // Pinta de cinza o v?rtice que est? sendo avaliado no momento, o que significa que ele acaba de ser descoberto.
    for(it = g[vA].begin(); it != g[vA].end(); it++) // Varre o vector, passando por todos os v?rtices adjacentes ao v?rtice u.
    {
        vB = *it; // Recebe o valor para que o iterador est? apontando
        printf("vB -> %d / vet[vB].ind -> %d/ idade -> %d\n", vB, vet[vB].ind, vet[vB].idade);
        if(final > vet[vB].idade) final = vet[vB].idade;
		
        if(cor[vB] == BRANCO) // Se o v?rtice(vB) adjacente ?quele que est? sendo avaliado(vA) ainda n?o tiver sido descoberto (branco).
		{
			printf("vB - %d/ vA - %d\n", vB, vA);			
            DFS_visit(vB); // A fun??o ? chamada, recursivam+ente, para avaliar o v?rtice adjacente.
        }
    }
    

    cor[vA] = PRETO; // Pinta de preto o v?rtice que est? sendo avaliado pela fun??o, j? que todos os v?rtices descendentes dele j? foram completamente avaliados (e tamb?m pintados de preto).
}


void DFS(int numeroDeVertices, int raiz){
    // Aloca??o din?mica
    cor = new int[numeroDeVertices];
    int vA, i;

    for(vA = 1; vA <= numeroDeVertices; vA++) // Coloca os valores iniciais em todas as posi??es dos vetores cor, descoberta e predecessor.
        cor[vA] = BRANCO;
        
    DFS_visit(raiz); // Chama uma segunda fun??o, que ser? utilizada recursivamente, enviando o v?rtice raiz como par?metro

}


int main()
{
	int N, M, I;
	int i, j, x, y, aux1, aux2;
	char op;
	while(scanf("%d", &N) != EOF){
		scanf("%d %d", &M, &I);
		vector<Vertice>::iterator it, it_aux;
	    g.resize(N+1);
	    vet.resize(N+1);
		fixo.resize(N+1);
		final = 101;
		int idade;
				
		for(i = 1; i <= N; i++){
			scanf("%d", &idade);
			Vertice v;
			v.ind = i;
			v.idade = idade;
			vet[i] = v;
			fixo[i] = v;
		}
		
		for(i = 0; i < M; i++){
			scanf("%d %d", &x, &y);
			//Testes - apagar
			if(y == 12) printf("-----------x = %d é adj-----------\n", x);
			if(x == 12) printf("-----------y = %d é adj-----------\n", y);
			g[y].push_back(x); 
		}
		printf("-----------------------------------------------------\n");
		
		getchar();
		for(i = 0; i < I; i++){
			final = 101;
			aux1 = 0; aux2 = 0;
			scanf("%c", &op);
	        getchar();
			if(op == 'T'){
				scanf("%d %d", &x, &y);
				getchar();
				for(j = 1; j <= N; j++){
					if(vet[j].ind == x){
						if(aux1 && aux2) break;
						printf("antes %d - %d\n", vet[j].ind, vet[j].idade);
						vet[j] = fixo[y];
						printf("trocou %d / %d - %d\n", j, vet[j].ind, vet[j].idade);
						printf("entrou no x\n");
						aux1 = 1;
					}
					if(vet[j].ind == y){
						if(aux1 && aux2) break;
						printf("antes %d - %d\n", vet[j].ind, vet[j].idade);
						vet[j] = fixo[x];
						printf("trocou %d / %d - %d\n", j, vet[j].ind, vet[j].idade);
						aux2 = 1;
						printf("entrou no y\n");
					}
					
				}
				//puts("troca feita");
			}else{
				scanf("%d", &x);
				getchar();
				DFS(N+1, vet[x].ind);
				if(final != 101)
					printf("%d\n", final);
				else puts("*");
			}
	
		}
	}
	system("PAUSE");
    return 0;
}
