//KRUSKAL



#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <time.h>
#include <algorithm>

using namespace std;



class grafo //ESTRUTURA DO GRAFO
{ 
    public:
        list <int> vertice; // Lista de vertices adjacentes.
	    list <int> valor; // Peso de cada adjacencia.	
		
    void insereVertice(int B,int P) // Fun��o para adicionar um vertice adjacente e o peso da adjacencia. 
    {
		vertice.push_back(B);
		valor.push_back(P);
    }	
};

class aresta // ESTRUTURA DAS ARESTAS
{
    public:
	    int vA;
		int vB;
		int peso;
		
        bool operator < ( const aresta &a) // Sobrecarga do operador < (menor), utilizado na fun��o sort(). O operador usar� o peso como par�metro.
    	{
            return peso <a.peso;       
        }
        friend ostream &operator<<(ostream & o, aresta & c) // Sobrecarga do operador <<, utilizado pelo comando cout na hora de imprimir os resultados.
        {
            o << c.vA << " - " << c.vB << ": " << c.peso << endl;
            return o;      
        }
};

grafo *GRAFO; 
list <aresta> ARESTA; // ARESTA � uma lista de (vA, vB, peso).

int main(){
    aresta aux;
    int N, M;
    cin >> N >> M;
    while(N != 0 && M != 0){
	    int i, j=0, k;
		int vA, vB, P; // Recebem os valores que ser�o adicionados no grafo.
		list <aresta>::iterator p; // Iterador para as arestas.
		list <int>::iterator p2,p3; // Iteradores para as listas de adjacencias dos v�rtices do grafo.
		grafo *MINIMO; // �rvore m�nima.
		int *vetor; // Vetor que mostra a que �rvore pertence cada v�rtice.
		
		// Aloca��o din�mica
		GRAFO = new grafo[N];
		MINIMO = new grafo[N];
		vetor = new int[N];
		
	    
		
	    for(i=0;i<M;i++) // L� o arquivo de entrada (entrada.txt)
	    {
		    cin >> vA;
			cin >> vB;
			cin >> P;
			GRAFO[vA].insereVertice(vB,P);
			GRAFO[vB].insereVertice(vA,P);
	    }
	     
	    // O grafo, que atualmente � representado por 
	    // um vetor de v�rtices-posi��es, onde cada posi��o cont�m uma lista com os v�rtices adjacentes ao v�rtice da posi��o e os respectivos pesos das adjacencias
	    // passa a ser representado por
	    // uma lista de objetos tipo aresta, sendo que cada objeto aresta cont�m os dois v�rtices adjacentes (vA e vB) e o peso da aresta.
		i=0; // N�mero de arestas lidas.
	    k=0; // Come�a o processo avaliando o v�rtice k, ou seja, a posi��o k do vetor GRAFO.
	    while(i!=(2*M)) // Enquanto o n�mero de arestas lidas for diferente do n�mero de arestas contidas no grafo. Como o grafo n�o � direcionado, cada aresta corresponde a duas arestas (ida e volta).
	    {
	   	    p2 = GRAFO[k].vertice.begin(); // Aponta o iterador p2 para o inicio da lista de v�rtices adjacentes a k.
	    	p3 = GRAFO[k].valor.begin();
	    	while(p2!=GRAFO[k].vertice.end()) // Enquanto o iterador n�o estiver apontando para o fim da lista de v�rtices adjacentes a k. Em outras palavras, passa por todos os v�rtices adjacentes a k.
	    	{
	            // Coloca os valores em um objeto auxiliar
	            aux.vA=k;
	        	aux.vB=*p2;
	        	aux.peso=*p3;
	        	
	        	ARESTA.push_back(aux); // Adiciona o objeto auxiliar � lista ARESTA.
	        	i++; // Incrementa I, j� que uma aresta acaba de ser lida.
	            p2++; p3++;
	        }
	        k++; // Incrementa k para que seja avaliado o pr�ximo v�rtice.
	    }
	    
	    // ---------------------------------------- KRUSKAL --------------------------------- // 
	    
	    ARESTA.sort(); // Ordena a lista ARESTA pelo peso das arestas. 
	    for(i=0;i<N;i++) vetor[i]=i; // Inicializa o vetor como se cada vertice pertencesse a uma arvore de apenas um vertice, o n�mero dado a cada �rvore � o n�mero do pr�prio v�rtice.    
	    
	    p = ARESTA.begin(); // Aponta o iterador para o inicio da lista ARESTA, ou seja, para a aresta com menor peso.
	        
	    // Este trecho poderia ser apagado, mas proporciona uma pequena economia de tempo computacional na avalia��o da primeira aresta.
	    // N�o � feita a pergunta vetor[vA]!=vetor[vB], j� que o vetor acabou de ser iniciado e todas suas posi��es s�o diferentes.
	    // Tamb�m n�o h� necessidade de passar por todas as posi��es do vetor verificando se algum outro v�rtice faz parte da mesma �rvore do v�rtice maior entre os dois pertencentes � primeira adjacencia.
	    // ---------------------------------------------------------------------------------- // 
	        // Recebe as informa��es da primeira aresta.    
	   	    vA = p->vA;
	        vB = p->vB;
	        P = p->peso;
	        // Adiciona a primeira aresta (aresta de menor peso) ao vetor MINIMO.  
	 	    MINIMO[vA].insereVertice(vB,P);
		    MINIMO[vB].insereVertice(vA,P);
	 
	        // Para padronizar, quando dois v�rtices passarem a fazer parte da mesma �rvore o n�mero desta �rvore ser� o n�mero do menor v�rtice.
	        // vA e vB passam a pertencer a mesma �rvore.
	        if(vA<vB)
	        	 vetor[vB] = vA; 
	        else
	        	 vetor[vA] = vB;  	
	 	    p++;
	    // ---------------------------------------------------------------------------------- //
	    
	    int menor, muda;
	    
	    while(p!=ARESTA.end()) // Enquanto o iterador n�o apontar para o fim da lista de arestas. Em outras palavras, percorre toda a lista de arestas.
	    {
	        // Recebe as informa��es da aresta a ser avaliada.
			vA = p->vA;
	    	vB = p->vB;
	    	P = p->peso;
				
			if(vetor[vA]!=vetor[vB]) // Se os v�rtices ligados pela aresta que est� sendo avaliada n�o pertencerem a mesma �rvore.
			{
	            // Adiciona a aresta que est� sendo avaliada ao vetor MINIMO.
		    	MINIMO[vA].insereVertice(vB,P);
		        MINIMO[vB].insereVertice(vA,P);
		        
				// Muda o indice da arvore ao qual o vertice pertence			  
		        if(vetor[vA]<vetor[vB]) // V� qual � o v�rtice cuja �rvore tem menor n�mero (atendendo ao padr�o).
	            {
	            	menor = vetor[vA];
	            	muda = vetor[vB];
		            for(i=0;i<N;i++) // Passa por todos os v�rtices, todos os que fizerem parte da mesma �rvore que o vB passam a fazer parte da �rvore do vA.
		            	if(vetor[i] == muda)
		            		vetor[i] = menor;
		        }
	            else
	            {
	            	menor = vetor[vB];
	            	muda = vetor[vA];
					for(i=0;i<N;i++) // Passa por todos os v�rtices, todos os que fizerem parte da mesma �rvore que o vA passam a fazer parte da �rvore do vB.
		            	if(vetor[i] == muda)
		              		vetor[i] = menor;
				}	
				
	    	} 
			p++; // Incrementa o iterador para que seja avaliada a pr�xima aresta.
		} 
		/*
		for(i=0;i<N;i++) cout << vetor[i]<< " ";
		cout<<endl;
		*/
		long long somaArestas = 0;
		int cont = 0, pesoAnt = 0; // soma das arestas da arvore geradora minima 
		bool achou;
		for(p = ARESTA.begin(); p != ARESTA.end(); p++){
			i = 0;
			achou = false;
			while(i < N){
				p3 = MINIMO[i].valor.begin();
				while(p3!=MINIMO[i].valor.end()){
					if(p->peso == *p3){
					achou = true; cont++;
					}
					p3++;
				}
			i++;
			}
			if(achou){
				if(p->peso == pesoAnt){
					if((cont-=2) >= 2)
						goto soma;
					else{
						cont = 0;
						goto naosoma;
					}
				}else{
					cont = 0;
				}
				soma:;
				somaArestas += p->peso;
				//cout << "PESO: " << p->peso << " / ";
			}
		naosoma:;
		pesoAnt = p->peso;
		p++;
		}
		cout << somaArestas << endl;
	
	    // Imprime a �rvore m�nima
	    /*
	    for(i=0;i<N;i++)
	    {
	        p2 = MINIMO[i].vertice.begin();
	        p3 = MINIMO[i].valor.begin();
	        cout << "Vertice["<<i<<"] ";
	        while(p2!=MINIMO[i].vertice.end())
	        {
	            cout << "--> " << *p2 << " - ";
	            cout << *p3 << " ";
	            p2++;
	            p3++;      
	        }
	        cout<<endl;               
	    }	 
		*/
	    //system("pause");
	cin >> N >> M;
	}
    return 0;   
}
