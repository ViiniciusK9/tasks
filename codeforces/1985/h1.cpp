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

const int MAX = int(1e6 + 10);

string mat[MAX];



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];
        }

        bool visited[n][m];
        memset(visited, false, sizeof(visited));
        ll maior = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                
                if (!visited[i][j])
                {
                    ll ans = 0;
                    queue<pi> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pi cur = q.front();
                        q.pop();
                        int x = cur.first;
                        int y = cur.second;

                        if (!visited[x][y])
                        {
                            ans++;
                            visited[x][y] = true;

                            if (x - 1 >= 0 && mat[x][y] == mat[x - 1][y])
                            {
                                q.push({x - 1, y});
                            }
                            if (y - 1 >= 0 && mat[x][y] == mat[x][y - 1])
                            {
                                q.push({x, y - 1});
                            }

                            if (x + 1 < n && mat[x][y] == mat[x + 1][y])
                            {
                                q.push({x + 1, y});
                            }
                            if (y + 1 < m && mat[x][y] == mat[x][y + 1])
                            {
                                q.push({x, y + 1});
                            }
                        }
                    }

                    maior = max(maior, ans);
                }
            }
        }

        cout << maior << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome