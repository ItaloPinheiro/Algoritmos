#include <cstdio>
#include <string.h>

int main(){
   int n, i, tam;
   scanf("%d", &n);
   getchar();
   while(n--){
      char frase[52];
      gets(frase);
      for(i = 0; i < strlen(frase); i++)
      {
         if(i == 0 && frase[i] >= 'a' && frase[i] <= 'z') //na primeira letra;
            putchar(frase[i]);
         else if(frase[i] >= 'a' && frase[i] <= 'z' && frase[i - 1] == ' ')
            putchar(frase[i]);
      }
      printf("\n");
   }
   return 0;
}
