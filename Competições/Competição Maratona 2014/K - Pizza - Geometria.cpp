#include <iostream>
#include <vector>
using namespace std;

int main(){
    int c, n, num, control, pos;
    bool sai;
    vector <int> vet;
    cin >> c >> n;
    control = c/n;
    for(int i = 0; i < n; i++){
        cin >> num;
        vet.push_back(num);
    }
    // roda a 1 e a 2 azeitona
    for(int i = vet[0]; i < vet[1]; i++){
        //roda as azeitonas
        sai = true;
        pos = i;
        for(int j = 1; j < n; j++){
            if(vet[j] <= pos) sai = false;
            pos += control;
            if(vet[j] > pos) sai = false;
        }
        if(vet[0] + c <= pos) sai = false;
        if(vet[0] + c > pos + control) sai = false;
        if(sai){
        cout << "S" << endl;
        return 0;
        }
    }
    cout << "N" << endl;
    return 0;
}
