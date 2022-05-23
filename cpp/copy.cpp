#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int n, i, l, r, a, j;
    int div, rest, maior;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> l >> r >> a;
        maior = 0;
        if(j % a == 0){
            maior = ((r - 1) / a) + ((r - 1) % a);
        }else {

            for(j = r; j > l; j--){
                if(j % a == a - 1){
                    maior = (j / a) + (j % a);
                    break;
                }

            }
        }
        DBG(maior);
    }
    return 0;
}

// g++ -o teste Teste.cpp
// ./teste