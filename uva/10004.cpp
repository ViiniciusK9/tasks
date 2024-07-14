#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;


const int MAX = int(212);

int adj[MAX][MAX];
int color[MAX];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    while (cin >> n && n != 0)
    {
        cin >> m;
        memset(adj, 0, sizeof(adj));
        memset(color, -1, sizeof(color));

        for (int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        queue<int> q;
        q.push(0);
        color[0] = 0;
        bool col = true;
        while (!q.empty() & col)
        {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                if (adj[cur][i] == 1) {

                    if (color[i] == -1) {
                        q.push(i);
                        color[i] = 1 - color[cur]; // (0 or 1) 
                    } else {
                        if (color[i] == color[cur]) {
                            col = false;
                            break;
                        }
                    }

                }
            }
            
        }

        if (col) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
        

        
    }
    


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome