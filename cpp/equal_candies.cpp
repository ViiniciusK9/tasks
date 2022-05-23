#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int n, i, j, aux, num, min_n = 99999999, quant = 0;
    int vet[60];
    cin >> n;
    while(n--){
        min_n = 99999999;
        quant = 0;
        cin >> aux;
        for(i = 0; i < aux; i++){
            cin >> num;
            vet[i] = num;
            min_n = min(min_n, num);
        }
        for(i = 0; i < aux; i++){
            if(vet[i] != min_n){
                quant += vet[i] - min_n;
            }
        }
        cout << quant << '\n';
    }
    return 0;
}

// g++ -o nome.cpp nome.exe