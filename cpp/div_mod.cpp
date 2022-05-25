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
        if(a > r){
            maior = r % a;
        } else if(r % a == a - 1){
            maior = (r / a) + (r % a);
        } else {
            
            int aux = r % a;
            int aux_r = r - aux - 1;
            if(aux_r < l){
                aux_r = r;
            }
            maior = (aux_r / a) + (aux_r % a);
        }
        cout << maior << '\n';
    }
    return 0;
}

// g++ -o teste Teste.cpp
// ./teste

// for(j = r; j > l; j--){
//                 int div = j / a;
//                 int rest = j % a;
//                 cout << "F " << a << " (" << j << ") = " << div << " - " << rest << " sum " << div + rest << "\n";
//                 maior = max(maior, (div + rest));

//             }


// if(j % a == 0){
//             maior = ((r - 1) / a) + ((r - 1) % a);
//         }