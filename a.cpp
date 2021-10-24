#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(2)<<(x)


int uri_1973(int argc, char const *argv[])
{
    long long n;
    long long carneiro = 0;
    long long estrela = 0;
    long long sum = 0;
    cin >> n;
    std::vector<long long int> vet(1000005);
    std::vector<long long int> aux(1000005);
    for(int i = 0; i < n; i++){
        cin >> vet[i];
        sum += vet[i];
        aux[i] = 0; 
    }
    int i = 0;
    while (i >= 0 && i <= n - 1){
        if(vet[i] % 2 != 0 && vet[i] > 0){
            if(aux[i] == 0){
                estrela++;
                aux[i] = 1;
            }
            carneiro++;
            vet[i]--;
            i++;
        } else if (vet[i] % 2 == 0 && vet[i] > 0){
            if(aux[i] == 0){
                estrela++;
                aux[i] = 1;
            }
            carneiro++;
            vet[i]--;
            i--;
        } else{
            break;
        }
    }
    cout << estrela << " " << sum - carneiro << endl;
    return 0;
}
