#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
  
using namespace std;
  
int main() {
    string carac, resf, res;
    char letraAnt;
  	int tam, tamanho;
	
    while (getline(cin,carac)) {
        int i = 0;
        vector<string> vcarac;
  
        while (carac[i] != '\0') {
            letraAnt = carac[i];
            string pfuncao = "";
            pfuncao += letraAnt;
  			//adiciona 1 à i antes de buscar o valor na string
            while (carac[++i] == letraAnt)
                pfuncao += letraAnt;
            //reduz 1 em i para quem pegue a letra diferente;
            i--;
            //codificando para colocar no vector
            res = "";
            tamanho = pfuncao.length();
             if (tamanho == 1) 
		        if (pfuncao == "1") 
		            vcarac.push_back("11");
		        else 
		             vcarac.push_back(pfuncao);  
		    else {
		        while (tamanho > 9) {
		            res += "9";
		            res += pfuncao[0];
		            tamanho -= 9;
		        }
		        // passando o tamanho para string
		  		stringstream num;
		  		string num1;
		  		num << tamanho;
		  		num >> num1; 
		        res += num1;
		        res += pfuncao[0];
		    vcarac.push_back(res);
		    }
            i++;
        }
  
    	resf = "";
  
        for (int j = 0, k = vcarac.size(); j < k; j++) {
            tam = 0;
			tam = vcarac[j].length();
  
            if (tam > 1)
                if (tam == 2 && vcarac[j][0] == '1')
                    resf += vcarac[j];
                else{
                    if (resf != "") {
                        cout << 1 << resf << 1;
                        resf = "";
                    }
                    cout << vcarac[j];
                }
            else 
                resf += vcarac[j];
        }
        if (resf != "") 
        cout << 1  << resf  << 1;
  
        cout << endl;
    }
return 0;
}
