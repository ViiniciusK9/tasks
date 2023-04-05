#include<bits/stdc++.h>
using namespace std;

#define MAX 11234567

int n, _p[MAX], _rank[MAX];

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



int main() {

    int ncases, succ, fail, c, u, v, first = 1;
    cin >> ncases;
    while (ncases--)
    {
        cin >> n; getchar();
        for (int i = 0; i < n; i++)
        {
            _p[i] = i;
            _rank[i] = 0;
        }
        succ = fail = 0;
        while ((c = getchar()) != '\n' && (c != EOF))
        {
            cin >> u >> v; getchar();
            u--;
            v--;
            if (c == 'c')
            {
                _union(u, v);
            } else if (c == 'q'){
                if (_find(u) == _find(v)) {
                    succ++;
                } else {
                    fail++;
                }
            }
            
        }
        if (first)
        {
            first = 0;
        } else {
            cout << '\n';
        }
        
        cout << succ << "," << fail << '\n';
    }
    

    return 0;
}