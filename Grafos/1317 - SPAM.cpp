#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>

using namespace std;

vector<bool> bfs(int inicio,vector< vector<int> > &g);

int main(){
	int N, M;
	cin>>N;
	while(N){
		string atributo[3];
		string nomes[N+1];
		vector< vector<int> > g(N+1);
		vector< vector<string> > atributov(N+1);
		M = N;
		int x,P;
		//g.resize(N+1);
		for(int i=1;i<=M;i++){
			cin >> x;
			while(x){
				g[i].push_back(x);
				cin >> x;
			}
		}
		cin >> P;
		while(P){
			int tamanho, T1, T2;
			vector<bool> cor = bfs(P,g);
			cin >> T1 >> T2;
			for(int i = 0; i < 3; i++){
				cin >> atributo[i];
			}
			for(int i = 1; i <= N; i++){
				//cout << "cor " << i << " - " << cor[i] << endl;
				if(cor[i]){
					//cout << i << " - " << g[i].size() << endl;
					tamanho = g[i].size();
					if(tamanho < T1) atributov[i].push_back(atributo[0]);
					else if(tamanho >= T1 && tamanho < T2) atributov[i].push_back(atributo[1]);
					else atributov[i].push_back(atributo[2]);
				}else atributov[i].push_back(atributo[0]);
			}
		cin >> P;
		}
		for(int i = 1; i <= N; i++){
			cin >> nomes[i];
		}
		for(int i = 1; i <= N; i++){
			//cout << i << " - " << atributov[i].size() << endl;
			cout<< nomes[i] << ":";
			for(int j = 0; j < atributov[i].size(); j++){
				cout <<" "<< atributov[i][j];           
			}
			cout << endl;
		}
		g.clear();
		atributov.clear();
	cin >> N;
	}
    return 0;
}

// Algoritmo calcula a menor distancia para alcançar todos os vertices do grafo partindo de um vertice inicial.
vector<bool> bfs(int inicio, vector< vector<int> > &g){
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
    return cor; // Retorna o vetor peso.
}

