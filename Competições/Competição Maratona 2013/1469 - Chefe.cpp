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
int *descoberta; // Tempo de descoberta
int *termino; // Tempo de t?rmino
int tempo; // "Rel?gio"

using namespace std;

vector< vector<int> > g;


void DFS_visit(int vA, int* idade)
{
     int vB;
     vector<int>::iterator it;
     cor[vA] = CINZA; // Pinta de cinza o v?rtice que est? sendo avaliado no momento, o que significa que ele acaba de ser descoberto.
     tempo++; // O tempo passa, uma vez que a chamada desta fun??o representa o percorrimento de uma aresta (afastando-se da raiz).
     descoberta[vA] = tempo; // Guarda o tempo em que o v?rtice foi descoberto. Em outras palavras, guarda o tempo em que a busca em profundidade passa pelo v?rtice pela primeira vez.

     for(it = g[vA].begin(); it != g[vA].end(); it++) // Varre o vector, passando por todos os v?rtices adjacentes ao v?rtice u.
     {
         vB = *it; // Recebe o valor para que o iterador est? apontando
         if(cor[vB] == BRANCO) // Se o v?rtice(vB) adjacente ?quele que est? sendo avaliado(vA) ainda n?o tiver sido descoberto (branco).
         {
			 printf("idade antes vA -> %d/ idade de vA -> %d\n", idade[predescessor[vA]], idade[vA]);
			 if(idade[predescessor[vA]] < idade[vA]){
             	predescessor[vB] = predescessor[vA]; // O predecessor do v?rtice adjacente se torna o v?rtice que est? sendo avaliado pela fun??o(vA).
			 } else predescessor[vB] = vA;
             DFS_visit(vB, idade); // A fun??o ? chamada, recursivamente, para avaliar o v?rtice adjacente.
         }
     }

     cor[vA] = PRETO; // Pinta de preto o v?rtice que est? sendo avaliado pela fun??o, j? que todos os v?rtices descendentes dele j? foram completamente avaliados (e tamb?m pintados de preto).
     termino[vA] = tempo; // Guarda o tempo em que todos os v?rtices descendentes daquele que est? sendo avaliado (vA) s?o completamente avaliados (e tamb?m pintados de preto). Em outras palavras, guarda o tempo em que a busca em profundidade passa pelo v?rtice pela segunda vez.
     tempo++; // O tempo passa, uma vez que o fim desta fun??o representa o percorrimento de uma aresta (aproximando-se da raiz).
}


void DFS(int numeroDeVertices, int raiz, int* idade)
{
    // Aloca??o din?mica
    cor = new int[numeroDeVertices];
    predescessor = new int[numeroDeVertices];
    descoberta = new int[numeroDeVertices];
    termino = new int[numeroDeVertices];
	idade[0] = 1000;
    int vA, i;

    for(vA = 0; vA < numeroDeVertices; vA++) // Coloca os valores iniciais em todas as posi??es dos vetores cor, descoberta e predecessor.
    {
        cor[vA] = BRANCO;
        descoberta[vA] = INF;
        predescessor[vA] = 0;
    }
	predescessor[1] = 0;
    tempo = -1; // Inicia tempo como -1 pois, como a fun??o DFS_visit o incrementa em seu inicio, o valor deste ser? 0 na execu??o da fun??o para o primeiro v?rtice (raiz).
    for(i = 1; i <= numeroDeVertices; i++){
		if(cor[i] == BRANCO){
            if(i > 1) raiz = i;
            printf("i -> %d/ raiz -> %d\n", i, raiz);
    		DFS_visit(raiz, idade); // Chama uma segunda fun??o, que ser? utilizada recursivamente, enviando o v?rtice raiz como par?metro.
		}
	}
	for(i = 1; i < numeroDeVertices; i++){
		printf("%d - %d\n", i, predescessor[i]);
	}
}


int main()
{
	int N, M, I;
	int i, x, y;
	char op;
	scanf("%d %d %d", &N, &M, &I);
	vector<int>::iterator it;
    g.resize(N+1);
	int idade[N+1];
	for(i = 1; i <= N; i++)
		scanf("%d", idade+i);

	for(i = 0; i < M; i++){
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
	}
	getchar();
	for(i = 0; i < I; i++){
		op = getchar();
		
		if(op == 'T'){
			scanf("%d %d", &x, &y);
			g[x].swap(g[y]);
			puts("troca feita");
		}else{
			scanf("%d", &x);
            DFS(N+1, 1, idade);
		}
	}
	
	for(i=1;i<=N;i++){
		cout<<i<<" = "<<descoberta[i]<<endl;
	}
	system("PAUSE");
    return 0;
}
