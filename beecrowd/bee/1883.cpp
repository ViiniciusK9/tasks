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

const int MAX = int(1123);

int mat[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
vector<pi> fire;

int m, n;

void bfss(pi s)
{
    queue<pi> q;
    int x, y;
    x = s.first;
    y = s.second;
    visited[x][y] = true;

    if (x + 1 < n && (mat[x + 1][y] == '.' || mat[x + 1][y] == 'E'))
    {
        q.push({x + 1, y});
        dist[x + 1][y] = 1;
    }

    if (x - 1 >= 0 && (mat[x - 1][y] == '.' || mat[x - 1][y] == 'E'))
    {
        q.push({x - 1, y});
        dist[x - 1][y] = 1;
    }

    if (y + 1 < m && (mat[x][y + 1] == '.' || mat[x][y + 1] == 'E'))
    {
        q.push({x, y + 1});
        dist[x][y + 1] = 1;
    }

    if (y - 1 >= 0 && (mat[x][y - 1] == '.' || mat[x][y - 1] == 'E'))
    {
        q.push({x, y - 1});
        dist[x][y - 1] = 1;
    }

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();
        x = cur.first;
        y = cur.second;

        if (!visited[x][y])
        {
            if (mat[x][y] == 'E') {
                
            }

            if (x + 1 < n && (mat[x + 1][y] == '.' || mat[x + 1][y] == 'E'))
            {
                q.push({x + 1, y});
                dist[x + 1][y] = dist[x][y] + 1;
            }

            if (x - 1 >= 0 && (mat[x - 1][y] == '.' || mat[x - 1][y] == 'E'))
            {
                q.push({x - 1, y});
                dist[x - 1][y] = dist[x][y] + 1;
            }

            if (y + 1 < m && (mat[x][y + 1] == '.' || mat[x][y + 1] == 'E'))
            {
                q.push({x, y + 1});
                dist[x][y + 1] = dist[x][y] + 1;
            }

            if (y - 1 >= 0 && (mat[x][y - 1] == '.' || mat[x][y - 1] == 'E'))
            {
                q.push({x, y - 1});
                dist[x][y - 1] = dist[x][y] + 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int xi, yi;
    cin >> t;
    char aux;
    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> aux;
                mat[i][j] = aux;

                if (aux == 'F')
                {
                    fire.pb({i, j});
                }
                else if (aux == 'S')
                {
                    xi = i;
                    yi = j;
                }
            }
        }

        bfss({xi, yi});
        bfsf();
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome