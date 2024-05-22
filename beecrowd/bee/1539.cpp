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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(110);
const int INF = int(1e9);

// vector<int> adj[MAX];
double adj[MAX][MAX];
double dista[MAX][MAX];


vector<pii> antenas;

double dist(pi a, pi b)
{
    return sqrt((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c, u, v, r, x, y;

    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        memset(adj, 0, sizeof(adj));
        memset(adj, 0, sizeof(dista));

        antenas.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> r;
            antenas.pb({x, {y, r}});
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    double ans = dist({antenas[i].f, antenas[i].s.f}, {antenas[j].f, antenas[j].s.f});

                    if (ans <= (double)(antenas[i].s.s))
                    {
                        adj[i + 1][j + 1] = ans;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    dista[i][j] = 0;
                else if (adj[i][j])
                    dista[i][j] = adj[i][j];
                else
                    dista[i][j] = INF;
            }
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dista[i][j] = min(dista[i][j], dista[i][k] + dista[k][j]);
                }
            }
        }

        cin >> c;
        int a, b;
        while (c--)
        {
            cin >> a >> b;

            if (dista[a][b] != INF) {
                cout << (int)dista[a][b] << '\n';
            } else {
                cout << "-1\n";
            }

        }
        


    }

    return 0;
    // g++ -O2 -Wall nome.cpp -o nome
}