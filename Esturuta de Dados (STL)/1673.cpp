#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>
  
using namespace std;
  
string codif(string temp) {
    int tamanho=0;
	tamanho = temp.size();
    if (tamanho == 1) 
        if (temp == "1") 
            return "11";
        else 
            return temp;     
    else {
    	string res= "";
        while (tamanho > 9) {
            res += "9";
            res += temp[0];
            tamanho -= 9;
        }
        // passando o tamanho para string
  		stringstream num;
  		string num1;
  		num << tamanho;
  		num >> num1; 
        res += num1;
        res += temp[0];
        //
        if (tamanho == 1){
		res += "1";
		}
    return res;
    }
  return "";
}
  
int main() {
    string carac, resf;
    char letraAnt;
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
            vcarac.push_back(codif(pfuncao));
            i++;
        }
  
    	resf = "";
  
        for (int j = 0, k = vcarac.size(); j < k; j++) {
			int tam = vcarac[j].length();
  
            if (tam > 1)
                if (tam == 2 && vcarac[j][0] == '1')
                    resf += vcarac[j];
                else{
                    if (resf != "") {
                        cout << "1" << resf << "1";
                        resf = "";
                    }
                    cout << vcarac[j];
                }
            else 
                resf += vcarac[j];
        }
  
        if (resf != "") 
        cout << "1" + resf + "1";
  
        cout << endl;
    }
return 0;
}
