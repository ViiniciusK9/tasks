#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 101

int n, _p[MAX], _rank[MAX];

int _find(int u) {
    // base case
    if (_p[u] == u)
    {
        return u;
    }

    // rec case
    return (_p[u] = _find(_p[u]));
}

void _union(int u, int v) {
    u = _find(u);
    v = _find(v);
    if (_rank[u] < _rank[v])
    {
        _p[u] = v;
    } else {
        _p[v] = u;
        if (_rank[u] == _rank[v])
        {
            _rank[u]++;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int freq[101];
    int t, m, u, v, _case = 1, quant;
    cin >> t;

    while (t--)
    {
        memset(freq, 0, sizeof(freq));
        
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            _rank[i] = 0;
            _p[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            _union(u, v);
        }
        quant = 0;
        for (int i = 0; i < n; i++)
        {
            u = _find(i);
            if (freq[_p[i]] == 0)
            {
                freq[_p[i]] = 1;
                quant++;
            }
            
            //cout << i << " " << _p[i] << ' ';
        }
        //cout << '\n';
        cout << "Caso #" << _case << ": ";
        if (quant > 1)
        {
            cout << "ainda falta(m) " << quant-1 << " estrada(s)\n";
        } else {
            cout << "a promessa foi cumprida\n";
        }
        
        _case++;
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome