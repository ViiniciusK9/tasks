#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 212345

typedef pair<int, int> ii;
typedef pair<int, ii> iii; // iii(wei, ii(u, v))

int n, _p[MAX], _rank[MAX];
vector<iii> eg;

// MUF - Make Union Find

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
    if (_rank[u] < _rank[v]) {
        _p[u] = v;
    } else {
        _p[v] = u;
        if (_rank[u] == _rank[v]) {
            _rank[u]++;
        }
    }
}

long long kruskal() {
    long long ans = 0, u, v, wei;
    ii e;
    for (u = 0; u < n; u++) _p[u] = u;
    sort(eg.begin(), eg.end());
    for (auto &it : eg) {
        e = it.second;
        wei = it.first;
        u = e.first; v = e.second;
        if (_find(u) != _find(v))
        {
            _union(u, v);
            ans += wei;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long m, x, y, z;
    
    while (cin >> n >> m)
    {
        if (n == m and m == 0)
        {
            break;
        }
        int aux = m;
        while (aux--)
        {
            cin >> x >> y >> z;
            eg.push_back(iii(z, ii(x, y)));
        }
        
        cout << kruskal() << '\n';
        eg.clear();
        
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome

// PROBLEMA IDENTICO AO 1152 POREM NÃO PRECISA SUBTRAIR DO TOTAL