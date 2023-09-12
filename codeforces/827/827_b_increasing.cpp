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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, aux;
    int vet[101];

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int f = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> aux;
            vet[j] = aux;
            for (int x = 0; x < j; x++)
            {
                if (aux == vet[x])
                {
                    f = 1;
                }
            }
        }
        if (f == 1)
        {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
        
    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe