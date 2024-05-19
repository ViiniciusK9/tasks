#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(2)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<double, pi> pii;

const int MAX = int(512);

int n, _p[MAX], _rank[MAX];
vector<pii> eg;

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

double kruskal() {
    long long u, v;
    double ans = 0;
    double wei;
    pi e;
    for (u = 1; u <= n; u++) _p[u] = u;
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

vector<pi> v;

double dist(pi a, pi b) {
    return sqrt(pow((a.f - b.f), 2) + pow((a.s - b.s), 2));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, x, y;

    cin >> c;

    while (c--)
    {
        cin >> n;
        memset(_p, 0,sizeof(_p));
        memset(_rank, 0,sizeof(_rank));

        eg.clear();
        v.clear();
        

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;

            v.pb({x, y});
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i != j) {
                    double valor = dist(v[i], v[j]);
                    //DBG(valor);
                    eg.pb({valor, {i+1, j+1}});
                }
            }
        }
        
        double ans = (kruskal()) / 100.0;
        //cout << kruskal(); << '\n';
        cout << F(ans) << '\n';

        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome