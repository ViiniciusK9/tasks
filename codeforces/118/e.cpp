#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = int(2e5 + 10);
const int EXPLORED = 2;
const int VISITED = 1;
const int UNVISITED = 0;

vi adj[MAX];
int n, m;
int dfsNumberCounter = 0;
int dfsRoot = 1;
int rootChildren = 0;
bool haveBridge = false;

array<bool, MAX> articulation_vertex;
array<int, MAX> dfs_num;
array<int, MAX> dfs_low;
array<int, MAX> dfs_parent;
vector<ii> response;

void graphCheck(int u)
{                          // DFS for checking graph edge properties
    dfs_num[u] = EXPLORED; // color u as EXPLORED instead of VISITED

    for (auto v : adj[u])
    {
        if (dfs_num[v] == UNVISITED)
        {
            dfs_parent[v] = u;
            graphCheck(v);
        }
        else if (dfs_num[v] == EXPLORED)
        {
            if (v == dfs_parent[u])
            {
                response.pb({v, u});
                //printf(" Two ways (%d, %d)-(%d, %d)\n", u, v, v, u);
            }
            else
            {
                response.pb({u, v});
                //printf(" Back Edge (%d, %d) (Cycle)\n", u, v);
            }
        }
        else if (dfs_num[v] == VISITED)
        {
            //printf(" Forward/Cross Edge (%d, %d)\n", u, v);
        }
    }

    dfs_num[u] = VISITED; // after recursion, color u as VISITED (DONE)
}

void articulationPointAndBridge(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

    for (auto v : adj[u])
    {
        if (dfs_num[v] == UNVISITED)
        {
            dfs_parent[v] = u;
            if (u == dfsRoot)
                rootChildren++;
            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u])
            {
                articulation_vertex[u] = true;
            }

            if (dfs_low[v] > dfs_num[u])
            {
                // printf(" Edge (%d, %d) is a bridge\n", u, v);
                haveBridge = true;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // -- on index??

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs_num.fill(UNVISITED);
    dfs_parent.fill(0);

    articulationPointAndBridge(1);
    if (!haveBridge)
    {
        dfs_num.fill(UNVISITED);
        dfs_parent.fill(0);

        graphCheck(1);
        //cout << response.size() << '\n';
        for (auto ed : response)
        {
            cout << ed.first << " " << ed.second << '\n';
        }
    } else {
        cout << "0\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome