#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

vector< vector<int> > g; // Lista de Adjacência

// Algoritmo calcula a menor distancia para alcançar todos os vertices do grafo partindo de um vertice inicial.
vector<int> bfs(int inicio){
	//para os 3 vetores a seguir, cada posição do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de distância minima para alcançar o vertice.
    vector<int> p(g.size(), -1); // Vetor que armazena o pai de cada vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou não.
    
	queue<int> Q; // Fila que define a ordem de acesso aos vertices.
	
	// Inicialização
    cor[inicio] = true; // Define a cor do vértice raiz como acessado.
    d[inicio] = 0; // Define a distância da raiz para ela mesma como 0.
    
    Q.push(inicio); // Enfileira a raiz.
    
    // Enquanto a fila não estiver vazia.
    while(!Q.empty()){
        int u = Q.front(); // Define u como sendo o vértice na frente na fila.
        Q.pop(); // Desenfileira.
        
        // Para todo vertice adjacente à "u".
        for(int i = 0; i < g[u].size(); i++){
            // Se o vertice adjacente à "u" não tiver sido encontrado.
			if(cor[g[u][i]] == false){
                Q.push(g[u][i]); // Enfileira o vertice adjacente.
                cor[g[u][i]] = true; // Define o vertice adjacente como encontrado.
                d[g[u][i]] = d[u]+1; // Define a distancia minima para alcançar o vertice.
                p[g[u][i]] = u; // Define o pai do vertice adjacente como "u".
            }
        }
    }
    
    // *** OBS: O RETORNO DA FUNÇÃO PODE SER ALTERADO CONFORME A NECESSIDADE DO PROBLEMA. ***
    return d; // Retorna o vetor peso.
}

int main(){
	vector <string> vet;
	vector <string>::iterator it_vet;
	int E, D, x, y, ver=1;
	cin >> E >> D;
	string nome1[E], nome2[E], n1, n2;
	for(int i = 0; i < E; i++){
		cin >> n1 >> n2;
		for(it_vet = vet.begin(); it_vet != vet.end(); it_vet++){
			if(*it_vet == n1) ver = 0;	
		}
		if(ver) vet.push_back(n1);
		ver = 1;
		
		for(it_vet = vet.begin(); it_vet != vet.end(); it_vet++){
			if(*it_vet == n2) ver = 0;
		}
		if(ver) vet.push_back(n2);
		
		nome1[i] = n1; nome2[i] = n2;
	}

	g.resize(vet.size()+1);
	
	for(int i = 0; i < E; i++){
		for(int j = 0; j < vet.size(); j++){
			if(vet[j] == nome1[i]) x = j; 
		}
		for(int k = 0; k < vet.size(); k++){
			if(vet[k] == nome2[i]) y = k; 
		}
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	set <string> myset;
	set <string>::iterator it_set;
	vector<int> dist = bfs(0);
	for(int i=1;i<vet.size();i++){
		if(dist[i] > 0 && dist[i] <= D){
			myset.insert(vet[i]);
		}
	}
	cout << myset.size() << endl;
	for(it_set = myset.begin(); it_set != myset.end(); it_set++){
		cout << *it_set << endl;
	}
    return 0;
}
