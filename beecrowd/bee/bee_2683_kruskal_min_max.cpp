#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1123456

typedef pair<int, int> ii;
typedef pair<int, ii> iii; // iii(wei ii(u, v)) 

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

long long kruskal_min() {
    long long ans = 0, u, v, wei;
    ii e;
    for (u = 0; u < n; u++) { _p[u] = u; _rank[u] = 0; }
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

long long kruskal_max() {
    long long ans = 0, u, v, wei;
    ii e;
    for (u = 0; u < n; u++) { _p[u] = u; _rank[u] = 0; }
    sort(eg.begin(), eg.end());
    reverse(eg.begin(), eg.end());
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

    cin >> n;
    int aux = n, u, v, wei;
    while (aux--)
    {
        cin >> u >> v >> wei;
        u--; v--;
        eg.push_back(iii(wei, ii(u, v)));
        
    }
    cout << kruskal_max() << '\n';    
    cout << kruskal_min() << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome