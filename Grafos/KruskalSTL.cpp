#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

class Aresta
{
	public:
		float w;
		int a;
		int b;
};



class Vertice {
    public:
       double r; // Rуtulo do vйrtice. (Peso da aresta ligada a este vertice)
       int ind; // Indice identificador do vйrtice.

       Vertice(){}

       Vertice(double r, int ind) {
			this->r = r;
			this->ind = ind;
       }
};

class Grafo {
    public:
        vector< vector<Vertice> > g;
        int n;
        float w;

        Grafo(const int &n) {
            this->n = n;
            g.resize(n);
        }
};

vector<int> v, r;
int n;

bool compare(Aresta A, Aresta B)
{
	return A.w < B.w;
}


int find(int k)
{
	if(k==v[k])
		return k;
	else{
		v[k] = find(v[k]);
	}
}

int unite(list<Aresta>::iterator it)
{
	int a, b;
	a = find(it->a);
	b = find(it->b);
	if (a == b){
		return 0;
	}
	
	if (r[a] > r[b]){
			v[b] = a;
	}
	
	else
	{
		v[a] = b;
		if (r[a] == r[b]){
			r[b]+=1;
		}
			
	}
	return 1;
}

float kruskal(const Grafo &G)
{
	Grafo A(n);
	Aresta insere;
	list<Aresta> listaAresta;
	list<Aresta>::iterator it;
	
	v.resize(A.n);
	r.assign(A.n, 0);
	int i, j, vert=0;

	A.w = 0.;

	for(i = 0; i < A.n; i++){
		v[i] = i;
	}

	for(i = 0; i < G.n; i++){
		for(j = 0; j < G.g[i].size(); j++){
			if(G.g[i][j].ind > i){
				insere.w = G.g[i][j].r;
				insere.a = i;
				insere.b = G.g[i][j].ind;
				listaAresta.push_back(insere);
			}
		}
	}

	listaAresta.sort(compare);

	for(it = listaAresta.begin(); vert<(A.n)-1 && it != listaAresta.end(); it++){
		if(unite(it)){
			A.g[it->a].push_back(Vertice(it->w, it->b));
			A.g[it->b].push_back(Vertice(it->w, it->a));
			A.w += it->w;
			vert++;
		}
	}

	return A.w;
}

int main(){

    int M=1,N=1,X,Y;
    double Z;
    while(M>0||N>0){
        cin>>M>>N;
        n=M;
        Grafo G(M+1);
        if(M>0||N>0){
            for(int i=0;i<N;i++){
                cin>>X>>Y>>Z;
                G.g[X].push_back(Vertice(Z,Y));
                G.g[Y].push_back(Vertice(Z,X));
            }
            long S = kruskal(G);
            cout<<S<<endl;
            G.g.clear();
            v.clear();
            r.clear();
        }

    }
    return 0;
}
