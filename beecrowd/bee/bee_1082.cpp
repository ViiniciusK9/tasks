#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 26


vector<int> ag[MAX];
int vis[MAX];


void dfs(int s, int x) {
    if (vis[s]) return;
    vis[s] = x;
    for (auto &j : ag[s]) dfs(j, x);
    return;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, v, e, case_ = 1, s, w, max, flag;
    char _s, _w;
    cin >> n;
    while (n--)
    {
        memset(vis, 0, sizeof(vis));
        cout << "Case #" << case_++ << ":\n";
        cin >> v >> e;
        for (int i = 0; i < e; i++)
        {
            cin >> _s >> _w;
            s = _s - 'a';
            w = _w - 'a';
            ag[s].push_back(w);
            ag[w].push_back(s);
        }
        
        int x = 1;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i]) {
                dfs(i, x);
                x++;
            }
        }
        max = x -1;
        x = 1;
        while (x <= v)
        {
            flag = 0;
            for (int i = 0; i < v; i++)
            {
                if (vis[i] == x)
                {
                    cout << (_s = 'a' + i) << ",";
                    flag = 1;
                }
                
            }
            x++;
            if (flag)
            {
                cout << '\n';
            }
            
        }

        cout << max << " connected components\n";
        

        cout << '\n';
        for (int i = 0; i < v; i++)
        {
            ag[i].clear();
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome