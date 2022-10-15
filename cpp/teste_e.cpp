#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int n, f = 0;
    int vet[1000009];
    int vet_a[1000009];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        if (vet_a[vet[i] + 1] != 0)
        {
            vet_a[vet[i] + 1]--;
            vet_a[vet[i]]++;
        }
        else {
            f++;
            vet_a[vet[i]]++;
        }
    }
    cout << f << '\n';

    return 0;
}

// g++ -o nome.cpp nome.exe