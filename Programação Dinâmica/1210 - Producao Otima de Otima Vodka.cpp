#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(){
	int i, tempo, idadeI, idadeF, pvenda;
	while(scanf("%d %d %d %d", &tempo, &idadeI, &idadeF, &pvenda) != EOF){
		int custo[idadeF], venda[idadeF + 1];
		int f[3][tempo + 1];
		int caminho[tempo + 1];
		vector<int> res;
		//puts("Custo no ano: ");
		for(i = 0; i < idadeF; i++)
			scanf("%d", custo+i); 
		//puts("\nVenda no ano: ");	
		for(i = 1; i <= idadeF; i++)
			scanf("%d", venda+i); 
		
		f[1][1] = custo[idadeI];
		f[2][1] = pvenda + custo[0] - venda[idadeI];
		//printf("f1 inicial -> %d / f2 inicial -> %d \n", f[1][1], f[2][1]);
		
		int idadef1 = idadeI + 1, idadef2 = 1;
		int nvf1,  nvf2, vf1, vf2, t1, t2;
		for(i = 2; i <= tempo; i++){
			caminho[i - 1] = 0;
			nvf1 = f[1][i - 1] + custo[idadef1];
			nvf2 = f[2][i - 1] + custo[idadef2];
			vf1 = f[1][i - 1] + pvenda + custo[0] - venda[idadef1];
			vf2 = f[2][i - 1] + pvenda + custo[0] - venda[idadef2];
			if(nvf1 < nvf2){
				idadef1++;
				t1 = nvf1;
			}
			else{
				idadef1 = idadef2 + 1;
				t1 = nvf2;
				res.push_back(i - 1);
			}
			//printf("\nnvf1 -> %d / nvf2 -> %d", nvf1, nvf2);
			
			if(vf1 < vf2) t2 = vf1;	
			else t2 = vf2;
			
			//printf("\nvf1 -> %d / vf2 -> %d\n", vf1, vf2);
			idadef2 = 1;
			f[1][i] = t1;
			f[2][i] = t2;
			//printf("t1 -> %d / t2 -> %d\n", t1, t2);
		//	if(t1 < t2) caminho[i] = 1;
		//	else caminho[i] = 2;
		}
		
		if(f[1][tempo] < f[2][tempo]){
			printf("%d\n", f[1][tempo]);
			caminho[tempo] = 0;
		}else{
			printf("%d\n", f[2][tempo]);
			caminho[tempo] = 1;
		}
		
		for(i = 0; i < res.size(); i++){
			if(i < res.size() - 1){
				printf("%d ", res[i]);
			}else printf("%d\n", res[i]);
		}
	}
	return 0;
}

