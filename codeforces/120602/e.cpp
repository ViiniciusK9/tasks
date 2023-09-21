#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

map<int, int> m;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x, aux;
    cin >> t;
    while (t--)
    {
        m.clear();
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            m[aux]++;
        }

        int h = m.begin()->first;
        int hh = m.begin()->first;
        int custo = 0;
        for (auto [i, j] : m)
        {
            custo += j * (i - hh);
            if ((x - custo) < 0) break;
            h++;
            x -= custo;
            //cout << i << " " << j << '\n';
        }

        if (x >= custo)
        {
            h += x/custo;
        }

        cout << h << '\n';
        
        
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome