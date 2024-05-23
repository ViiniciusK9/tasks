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

const int MAX = 11;
const int INF = int(1e9);

vector<pi> adj[MAX][MAX];

bool visited[MAX][MAX];
int dist[MAX][MAX];

int bfs(pi so, pi dest)
{
    int xi, yi, wi;
    queue<pii> q;

    xi = so.f;
    yi = so.s;

    q.push({xi,{yi, 0}}); 

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        xi = cur.f;
        yi = cur.s.f;
        wi = cur.s.s;

        if (xi == dest.f && yi == dest.s) {
            return wi;
        }

        if (!visited[xi][yi])
        {
            visited[xi][yi] = true;

            for (auto vi : adj[xi][yi])
            {
                q.push({vi.f,{vi.s,wi+1}});
            }
        }
    }

    return INF;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a1;

    while (cin >> n)
    {
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = n-1; j >= 0; j--)
            {
                cin >> a1;
                if (a1 == 1) {
                    adj[i][j].pb({});
                }

                cin >> a1;
                if (a1 == 1) {
                    adj[i][j].pb({});
                }

                cin >> a1;
                if (a1 == 1) {
                    adj[i][j].pb({});
                }

                cin >> a1;
                if (a1 == 1) {
                    adj[i][j].pb({});
                }
            }
        }

        int qn, xi, yi, xf, yf;

        cin >> qn;

        while (qn--)
        {
            memset(visited, false, sizeof(visited));
            memset(dist, 0, sizeof(dist));
            cin >> xi >> yi >> xf >> yf;

            int ans = bfs({xi, yi}, {xf, yf});

            if (ans == INF) {
                cout << "Impossible\n";
            } else {
                cout << ans << '\n';
            }

        }


    }
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome