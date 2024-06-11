#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, m, aux;
    map<int, int> _map;
    cin >> m >> r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> aux;
            _map[j] += aux;
        }
    }
    int maior = 0;
    int i_maior = 0;
    int i = 0;
    for (auto &j : _map)
    {
        i++;
        if (j.second >= maior)
        {
            maior = j.second;
            i_maior = i;
        }
        
    }
    
    cout << i_maior << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nomes