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

const int MAX = 2e5 + 10;

int ph;

vi adj[MAX];
array<bool, MAX> visited;
vector<vector<int>> vet;

vector<int> al;

void dfs(int sr)
{
    visited[sr] = true;

    al.pb(sr);

    int fi = 0;
    for (auto node : adj[sr])
    {
        if (!visited[node])
        {
            dfs(node);
        }
        fi++;
    }

    if (fi == 0)
    {
        if (al.size() >= 1)
        {
            vet.pb(al);
            al.clear();
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vi p(n);
        int root = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == i + 1)
            {
                root = i + 1;
            }
            else
            {
                adj[p[i]].pb(i + 1);
            }
        }

        ph = 0;

        dfs(root);

        cout << vet.size() << '\n';
        for (auto el : vet)
        {
            cout << el.size() << '\n';

            for (int i = 0; i < el.size(); i++)
            {
                cout << (i == 0 ? "" : " ") << el[i];
            }
            cout << '\n';
        }

        cout << (t == 0 ? "" : "\n");
        

        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }

        vet.clear();
        visited.fill(false);
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome