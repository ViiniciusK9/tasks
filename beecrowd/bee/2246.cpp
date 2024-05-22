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

int mat[210][210];

bool visited[210][210];
int n, m;

int bfs(pi source)
{
    int ans = 0;

    queue<pi> q;

    q.push(source);
    int value = mat[source.f][source.s];

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();

        int i, j;

        i = cur.f;
        j = cur.s;

        if (!visited[i][j]) {
            ans++;
            visited[i][j] = true;

            if (i + 1 < n && mat[i+1][j] == value) {
                q.push({i+1, j});
            }

            if (i - 1 >= 0 && mat[i-1][j] == value) {
                q.push({i-1, j});
            }

            if (j + 1 < m && mat[i][j+1] == value) {
                q.push({i, j+1});
            }

            if (j - 1 >= 0 && mat[i][j-1] == value) {
                q.push({i, j-1});
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
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    //memset(visited, false, sizeof(visited));

    int ans = int(1e9);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j]) {
                int var = bfs({i,j});
                ans = min(ans, var);
            }
        }
    }
    
    cout << ans << '\n';

    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome