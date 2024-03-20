#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    int nb[1123][1123];
    cin >> n >> m;

    memset(nb, 0, sizeof(nb));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        nb[a][b]++;
        nb[b][a]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        int qnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (nb[i][j] == 1) qnt+=nb[i][j];
        }
        
        if (qnt % 2 != 0) {
            cout << "Rambo esta perdido\n";
            return 0;
        }
    }
    
    // verificar se é um grafo conexo e se os vertices possuem grau par

    cout << "Rambo esta salvo\n";

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome