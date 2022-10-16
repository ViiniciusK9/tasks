#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int const M = (int) 2 * 10e5 + 1;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n, q;
    long long vet_n[M];
    long long vet_sum_n[M];
    long long vet_q[M];
    set<long long> set_v;

    while (t--)
    {
        cin >> n >> q;
        int maior, soma = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> vet_n[i];
            soma += vet_n[i];
            vet_sum_n[i] = soma;
            if (i == 0)
            {
                maior = vet_n[i];
            } else if (vet_n[i] > maior) {
                maior = vet_n[i];
            }
            set_v.insert(maior);
            vet_n[i] = maior;
        }
        for (int i = 0; i < q; i++)
        {
            cin >> vet_q[i];
        }
        
        

    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe