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

string mat[1123];
bool visited[1123][1123];

int n, m;

void bfs(pi source)
{
    int i, j;
    i = source.f;
    j = source.s;
    queue<pi> q;
    visited[i][j] = true;

    if (i + 1 < n && visited[i+1][j] == false && mat[i+1][j] == '.')
    {
        q.push({i + 1, j});
    }

    if (i - 1 >= 0 && visited[i-1][j] == false && mat[i-1][j] == '.')
    {
        q.push({i - 1, j});
    }

    if (j + 1 < m && visited[i][j+1] == false && mat[i][j+1] == '.')
    {
        q.push({i, j + 1});
    }

    if (j - 1 >= 0 && visited[i][j-1] == false && mat[i][j-1] == '.')
    {
        q.push({i, j - 1});
    }

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();
        i = cur.f;
        j = cur.s;

        if (!visited[i][j] && mat[i][j] == '.')
        {
            visited[i][j] = true;
            if (i + 1 < n && visited[i+1][j] == false && mat[i+1][j] == '.')
            {
                q.push({i + 1, j});
            }

            if (i - 1 >= 0 && visited[i-1][j] == false && mat[i-1][j] == '.')
            {
                q.push({i - 1, j});
            }

            if (j + 1 < m && visited[i][j+1] == false && mat[i][j+1] == '.')
            {
                q.push({i, j + 1});
            }

            if (j - 1 >= 0 && visited[i][j-1] == false && mat[i][j-1] == '.')
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

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.' && visited[i][j] == false)
            {
                ans++;
                bfs({i, j});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome