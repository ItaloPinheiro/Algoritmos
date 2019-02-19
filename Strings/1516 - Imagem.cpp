#include <iostream>
#include <string.h> 

using namespace std;
 
int main(){
    int n, m, a, b, i, j, k, l;
    char v[101][101];
    cin >> n >> m;
    while(n!=0 && m!=0){
    getchar();
        for(i = 0; i < n; i++)
        gets(v[i]);      
        cin >> a >> b;
        for(i = 0; i < n; i++)
            for(k = 0; k < (a/n); k++){
                for(j = 0; j < m; j++)
                    for(l = 0; l < (b/m); l++)
                        cout << v[i][j];
                cout << endl;
        	}
        cout << endl;
    cin >> n >> m;
    }
    return 0;
}

