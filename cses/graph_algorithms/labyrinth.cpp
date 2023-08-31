#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1123

int n, m;

vector<string> gr;
int vis[MAX][MAX];


int busca(int i, int j)
{
    int u, v;
    pair<int, int> ii;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {

        u = q.front().first;
        v = q.front().second;

        if (vis[u][v] != -1) continue;

        if (gr[u][v] == 'B')
        {
            return 1;
        }
        

        if (u - 1 > 0 && u - 1 < n && vis[u-1][v] == -1 && gr[u-1][v] != '#')
        {
            q.push({u-1, v});            
        }

        if (u + 1 > 0 && u + 1 < n && vis[u + 1][v] == -1 && gr[u+1][v] != '#')
        {
            q.push({u + 1, v});            
     
        }

        if (v - 1 > 0 && v - 1 < m && vis[u][v - 1] == -1 && gr[u][v-1] != '#')
        {
            q.push({u, v - 1});            
        }

        if (v + 1 > 0 && v + 1 < m && vis[u][v + 1] == -1 && gr[u][v+1] != '#')
        {
            q.push({u, v + 1});            
        }
        
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        gr.push_back(s);
    }
    
    memset(vis, -1, sizeof(vis));

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(gr[i][j] == 'A')
            {
                ans = busca(i, j);
                break;
            }
        }
        if (ans != -1) break;
    }

    cout << ans << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome