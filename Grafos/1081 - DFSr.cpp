#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iomanip>


#define INF -1 // N?o descoberto (desconexo).
#define NUL -2 // Orf?o (raiz).
#define PRETO 0 // Descendentes j? est?o pretos ou n?o tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // N?o descoberto.


int *cor;
int *predescessor;
int *descoberta; // Tempo de descoberta
int *termino; // Tempo de t?rmino
int tempo; // Rel?gio

using namespace std;

vector<int> *listaDeAdjascencias;


void DFS_visit(int vA, int space, int fspace)
{
     int vB;
     vector<int>::iterator it;
     cor[vA] = CINZA; // Pinta de cinza o v?rtice que est? sendo avaliado no momento, o que significa que ele acaba de ser descoberto.
     tempo++; // O tempo passa, uma vez que a chamada desta fun??o representa o percorrimento de uma aresta (afastando-se da raiz).
     descoberta[vA] = tempo; // Guarda o tempo em que o v?rtice foi descoberto. Em outras palavras, guarda o tempo em que a busca em profundidade passa pelo v?rtice pela primeira vez.

     for(it=listaDeAdjascencias[vA].begin(); it!=listaDeAdjascencias[vA].end(); it++) // Varre o vector, passando por todos os v?rtices adjacentes ao v?rtice u.
     {
     	//cout << "space -> " << space  << " - fspace -> " << fspace << endl;
         vB = *it; // Recebe o valor para que o iterador est? apontando
         if(cor[vB] == BRANCO) // Se o v?rtice(vB) adjacente ?quele que est? sendo avaliado(vA) ainda n?o tiver sido descoberto (branco).
         {
             cout << fixed << setw(space) << right << vA << "-" << vB << " pathR(G," << vB <<")" << endl;
             space += fspace;
             predescessor[vB] = vA; // O predecessor do v?rtice adjacente se torna o v?rtice que est? sendo avaliado pela fun??o(vA).
             DFS_visit(vB, space, fspace); // A fun??o ? chamada, recursivamente, para avaliar o v?rtice adjacente.
         }
		 else if(cor[vA] == CINZA){
		 	//printf("------predecessor[%d] = %d / vA = %d\n", vB, predescessor[vB] ,vA);
		  	cout<<fixed<<setw(space)<<right<<vA<<"-"<<vB<<endl;
		  	 if(*it)
			space += fspace;
		}
	 if(*it)
	 space -= fspace;
     }
     cor[vA] = PRETO; // Pinta de preto o v?rtice que est? sendo avaliado pela fun??o, j? que todos os v?rtices descendentes dele j? foram completamente avaliados (e tamb?m pintados de preto).
     termino[vA] = tempo; // Guarda o tempo em que todos os v?rtices descendentes daquele que est? sendo avaliado (vA) s?o completamente avaliados (e tamb?m pintados de preto). Em outras palavras, guarda o tempo em que a busca em profundidade passa pelo v?rtice pela segunda vez.
     tempo++; // O tempo passa, uma vez que o fim desta fun??o representa o percorrimento de uma aresta (aproximando-se da raiz).
}


void DFS(int numeroDeVertices, int raiz)
{
    // Aloca??o din?mica
    int space=3, fspace = 2;
    cor = new int[numeroDeVertices];
    predescessor = new int[numeroDeVertices];
    descoberta = new int[numeroDeVertices];
    termino = new int[numeroDeVertices];

    int vA;

    for(vA=0;vA<numeroDeVertices;vA++) // Coloca os valores iniciais em todas as posi??es dos vetores cor, descoberta e predecessor.
    {
        cor[vA] = BRANCO;
        descoberta[vA] = INF;
        predescessor[vA] = NUL;
    }

    tempo = -1; // Inicia tempo como -1 pois, como a fun??o DFS_visit o incrementa em seu inicio, o valor deste ser? 0 na execu??o da fun??o para o primeiro v?rtice (raiz).
    /*
    for(int i=1;i<=numeroDeVertices;i++){
		if(cor[i]==BRANCO) DFS_visit(raiz, space, fspace); // Chama uma segunda fun??o, que ser? utilizada recursivamente, enviando o v?rtice raiz como par?metro.
	}
	/*
	for(int i = 0; i < numeroDeVertices; i++){
		cout << endl << "v: " << i << "Cor: " << cor[i] << endl;
	}*/
    
	for(int i=0;i<=numeroDeVertices;i++){
		if(cor[i]==BRANCO){
			raiz = i;
			space = 3;
			if(raiz > 9){
				space++;
			}
    		DFS_visit(raiz, space, fspace); // Chama uma segunda fun??o, que ser? utilizada recursivamente, enviando o v?rtice raiz como par?metro.
    		if(!listaDeAdjascencias[i].empty()){
    		cout << endl;}
    	}
	}
}


int main(){
	int n, casos = 1;
	cin >> n;
	while(casos <= n){
		int V,M;
		cin>>V>>M;
		bool adj[V][V];
		for(int i=0;i<V;i++)
			for(int j = 0; j < V; j++)
				adj[i][j] = false;
    	
	    listaDeAdjascencias = new vector<int> [V+1];
	    int x,y;
		for(int i=0;i<M;i++){
			cin>>x>>y;
			adj[x][y] = true;
		}
		for(int i=0;i<V;i++)
			for(int j = 0; j < V; j++)
				if(adj[i][j]) listaDeAdjascencias[i].push_back(j);
		
		cout << "Caso " << casos << ":" << endl;
		DFS(V+1,0);
	casos++;	
	}
		system("pause");
	    return 0;
}

