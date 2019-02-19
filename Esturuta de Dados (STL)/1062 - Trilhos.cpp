#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	int vag, nvag, i;
	while(scanf("%d", &vag) && vag){
		int vet[vag+1];
		while(scanf("%d", &nvag) && nvag){
			vet[1] = nvag;
			for(i = 2; i < vag+1; i++){
				scanf("%d", &nvag);
				vet[i] = nvag;
			}
			stack<int> p;
			int cont = 1;
			p.push(cont); i = 1;
			while(1){
				if(p.empty()){
					puts("Yes"); break;
				}
				printf("em cima -> %d / vet[%d] -> %d\n", p.top(), i, vet[i]);
				if(cont == vag && p.top() != vet[i]){
					puts("No"); break;
				}
				while(p.top() == vet[i]){
					printf("em cima -> %d / vet[%d] -> %d\n", p.top(), i, vet[i]);
					p.pop(); i++;
					if(p.empty())break;
				}
				if(cont != vag)
					p.push(++cont);
			}
		}
		if(!nvag) puts("");
	}
}
