#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 112345

int n, vis[MAX], nei[MAX];

map<string, int> s2u; // map utilizado para converter as string para um valor inteiro que ira representar o vertice

int dfs(int u, int l) {
    if (vis[u])
    {
        return vis[u] == l;
    }

    vis[u] = l;
    return dfs(nei[u], l);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(vis, 0, sizeof(vis));

    int u, v;
    n = 0;
    string s1, s2;
    while (cin >> s1)
    {
        cin >> s2;
        if (!(s2u[s1]))
        {
            s2u[s1] = n;
            u = n;
            n++;
        } else {
            u = s2u[s1];
        }
        if (!(s2u[s2]))
        {
            s2u[s2] = n;
            v = n;
            n++;
        } else {
            v = s2u[s2];
        }
        nei[u] = v;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += dfs(i, i+1);
    }
    cout << ans << '\n';
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome