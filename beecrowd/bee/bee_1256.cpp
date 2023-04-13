#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t, m, n, aux;

    cin >> t;
    while (t--)
    {
        vector<vector<int>> vet(100);
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet[aux % m].push_back(aux);
        }
        for (int i = 0; i < m; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < vet[i].size(); j++)
            {
                cout << vet[i][j] << " -> ";
            }
            cout << "\\" << "\n";
        }
        if (t != 0)
        {
            cout << '\n';
        }
        
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome