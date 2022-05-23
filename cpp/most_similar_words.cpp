#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int diferenca_strings(string a, string b, int tam){
    int i, diferenca = 0;
    for(i = 0; i < tam; i++){
        diferenca += fabs((int)a[i] - (int)b[i]); 
    }
    return diferenca;
}


int main(int argc, char const *argv[])
{
    int t, n, m, i, j, min_n;
    string matriz[50];
    string a;
    cin >> t;
    while (t--){
        min_n = 99999999;
        cin >> n >> m;
        for (i = 0; i < n; i ++){
            cin >> a;
            matriz[i] = a;
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i != j){
                    //cout << " i: " << matriz[i] << " j: " << matriz[j] << '\n';
                    min_n = min(diferenca_strings(matriz[i], matriz[j], m), min_n);
                }
            }
        }
        cout << min_n << '\n';
    }
    
    return 0;
}

// g++ -o nome.cpp nome.exe