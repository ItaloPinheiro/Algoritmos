#include <iostream>
#include <string.h>
using namespace std;

int main(){
   int n, i, tam;
   cin >> n;
   getchar();
   while(n--){
      string frase;
      getline(cin,frase);
      for(i = 0; i < frase.length(); i++)
      {
         if(i == 0 && frase[i] >= 'a' && frase[i] <= 'z') //na primeira letra;
            cout << frase[i];
         else if(frase[i] >= 'a' && frase[i] <= 'z' && frase[i - 1] == ' ')
            cout << frase[i];
      }
      cout << endl;
   }
   return 0;
}
