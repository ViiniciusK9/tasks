#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, u , v;
    cin >> t;
    map<int, int> _map;
    vector<pair<int, int>> vet;

    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            _map[u]++;
            _map[v]++;
        }
        int a1 = 0, a2 = 0;
        for (auto &j : _map)
        {
            /*
            if (j.second == 1)
            {
                continue;
            } else {
                if (a1 == 0)
                {
                    a1 = j.second;
                    ia1++;
                } else if (a1 == j.second) {
                    ia1++;
                } else if (a2 == 0) {
                    a2 = j.second;
                    ia2++;
                } else {
                    ia2++;
                }
                
            }
            */
            vet.push_back({j.second, j.first});
            
        }

        sort(vet.rbegin(), vet.rend());
        
        //cout << vet[0].first << " " << vet[1].first-1 << '\n';
        /*
        if (ia2 == 1)
        {
            cout << a2 << " "  << a1-1 << '\n';
        } else {
            cout << a1 << " "  << a2-1 << '\n';
        }
        */

        int i = 0;
        a1 = 0, a2 = 0;
        a1 = vet[0].first;
        i++;

        while (i < vet.size())
        {
            if (vet[i].first != a1)
            {
                a2 = vet[i].first;
                break;
            } else {
                i++;
            }
        }

        if (i == 1)
        {
            cout << a1 << " " << a2 -1 << '\n';
        } else {
            cout << a2 << " " << a1-1 << '\n'; 
        }
        

        vet.clear();
        _map.clear();
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome