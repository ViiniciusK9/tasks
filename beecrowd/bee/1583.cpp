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

int n, m;
string mat[55];
string aux[55];
bool visited[55][55];

void bfs(pi so)
{
    int i, j;
    i = so.f;
    j = so.s;

    queue<pi> q;

    visited[i][j] = true;

    if (i + 1 < n && visited[i + 1][j] == false && mat[i + 1][j] == 'A')
    {
        q.push({i + 1, j});
    }

    if (i - 1 >= 0 && visited[i - 1][j] == false && mat[i - 1][j] == 'A')
    {
        q.push({i - 1, j});
    }

    if (j + 1 < m && visited[i][j + 1] == false && mat[i][j + 1] == 'A')
    {
        q.push({i, j + 1});
    }

    if (j - 1 >= 0 && visited[i][j - 1] == false && mat[i][j - 1] == 'A')
    {
        q.push({i, j - 1});
    }

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();
        i = cur.f;
        j = cur.s;

        if (!visited[i][j] && mat[i][j] == 'A')
        {
            visited[i][j] = true;
            aux[i][j] = 'T';
            mat[i][j] = 'T';
            if (i + 1 < n && visited[i + 1][j] == false && mat[i + 1][j] == 'A')
            {
                q.push({i + 1, j});
            }

            if (i - 1 >= 0 && visited[i - 1][j] == false && mat[i - 1][j] == 'A')
            {
                q.push({i - 1, j});
            }

            if (j + 1 < m && visited[i][j + 1] == false && mat[i][j + 1] == 'A')
            {
                q.push({i, j + 1});
            }

            if (j - 1 >= 0 && visited[i][j - 1] == false && mat[i][j - 1] == 'A')
            {
                q.push({i, j - 1});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m)
    {
        memset(visited, false, sizeof(visited));
        if (n == m && n == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];
            aux[i] = mat[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == false && mat[i][j] == 'T')
                {
                    bfs({i, j});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << mat[i] << '\n';
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome