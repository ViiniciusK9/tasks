#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 51234

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

int kruskal() { // use long long if necessary
    int ans = 0, u, v;
    for (u = 0; u < n; u++) _p[u] = u;
    sort(eg.begin(), eg.end());
    for (auto &[wei, e] : eg) {
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

    int cases, m, cnt, wei, u, v, first = 1;

    cin >> cases;

    while (cases--)
    {
        map<string, int> s2u;
        cin >> n >> m;

        cnt = 0;
        while (m--)
        {
            string s1, s2;
            cin >> s1 >> s2 >> wei;
            u = s2u.find(s1) == s2u.end() ? (s2u[s1] = cnt++) : s2u[s1];
            v = s2u.find(s2) == s2u.end() ? (s2u[s2] = cnt++) : s2u[s2];
            eg.push_back(iii(wei, ii(u, v)));
        }

        if (first)
        {
            first = 0;
        } else {
            cout << '\n';
        }
        
        cout << kruskal() << '\n';
        eg.clear();


    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome