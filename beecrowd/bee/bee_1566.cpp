#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 231

int vet[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux;
    cin >> t;
    while (t--)
    {
        memset(vet, 0, sizeof(vet));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet[aux]++;
        }
        int first = 0;
        for (int i = 0; i < MAX; i++)
        {
            while (vet[i]--)
            {
                if (!first)
                {
                    cout << i;
                    first = 1;
                } else {
                    cout << " " << i;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome