#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 1123


int n, ag[MAX][MAX], vis[MAX];

int dfs(int u, int c) {
    int v, ans = 1;
    if (vis[u]) 
    {
        return vis[u] == c;
    }
    vis[u] = c;
    for (v = 0; v < n; v++)
    {
        if (ag[u][v])
        {
            ans &= dfs(v, c ^ 3);
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int u, v, ans = 1;
    cin >> n;
    for (u = 0; u < n; u++)
    {
        vis[u] = 0;
        for (v = 0; v < n; v++)
        {
            cin >> ag[u][v];
            ag[u][v] = !ag[u][v];
        }
    }
    
    for (u = 0; u < n; u++)
    {
        if(!vis[u]) ans &= dfs(u, 1);
    }
    cout << (ans ? "Bazinga!\n" : "Fail!\n");
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome