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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(512);
const int INF = int(1e9);


string mat[MAX];

bool visited[MAX][MAX];
int n,m;
int dist[MAX][MAX];

int bfs(pii source)
{
    int x, y, w;
    int ans = INF;
    x = source.f;
    y = source.s.f;
    w = source.s.s;
    dist[x][y] = 0;
    queue<pii> q;
    q.push(source);

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        x = cur.f;
        y = cur.s.f;
        w = cur.s.s;

        if (mat[x][y] == 'E')
        {
            ans = min(ans, w);
        }

        if (!visited[x][y]) {
            visited[x][y] = true;

            if (x + 1 < n && mat[x+1][y] != '#') {
                if (mat[x+1][y] != '.' && mat[x+1][y] != 'E' && mat[x+1][y] != 'H') {
                    int va = mat[x+1][y] - '0';
                    q.push({x+1, {y, w + va}});
                } else {
                    q.push({x+1, {y, w}});
                }
            }

            if (x - 1 >= 0 && mat[x-1][y] != '#') {
                if (mat[x-1][y] != '.' && mat[x-1][y] != 'E' && mat[x-1][y] != 'H') {
                    int va = mat[x-1][y] - '0';
                    q.push({x-1, {y, w + va}});
                } else {
                    q.push({x-1, {y, w}});
                }
            }
            // y
            if (y + 1 < m && mat[x][y+1] != '#') {
                if (mat[x][y+1] != '.' && mat[x][y+1] != 'E' && mat[x][y+1] != 'H') {
                    int va = mat[x][y+1] - '0';
                    q.push({x, {y+1, w + va}});
                } else {
                    q.push({x, {y+1, w}});
                }
            }

            if (y - 1 >= 0 && mat[x][y-1] != '#') {
                if (mat[x][y-1] != '.' && mat[x][y-1] != 'E' && mat[x][y-1] != 'H') {
                    int va = mat[x][y-1] - '0';
                    q.push({x, {y-1, w + va}});
                } else {
                    q.push({x, {y-1, w}});
                }
            }

        }
    }
    
    return ans;
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

    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'H') {
                x = i;
                y = j;
                break;
            }
        }
        
    }

    int ans = bfs({x, {y, 0}});
    
    if (ans == INF) {
        cout << "ARTSKJID\n";
    } else {
        cout << ans << '\n';
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome