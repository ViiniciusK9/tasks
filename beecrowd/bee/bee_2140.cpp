#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vet[6] = {2, 5, 10, 20, 50, 100};

    int vet_2[21];
    int aux = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 6; j++)
        {
            vet_2[aux] = vet[i] + vet[j];
            //DBG(aux);
            aux++;
        }
    }

    int n, m;
    cin >> n >> m;
    while (n != 0 and m != 0)
    {
        int troco = m - n;
            aux = 0;
            for (int i = 0; i < 21; i++)
            {
                if (vet_2[i] == troco) {
                    aux = 1;
                    cout << "possible\n";
                    break;
                }
            }
            if (!aux)
            {
                cout << "impossible\n";
            }
        cin >> n >> m;
    }
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome