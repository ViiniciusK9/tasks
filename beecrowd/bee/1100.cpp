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


bool visited[10][10];
int dist[10][10];

int bfs(pi source, pi dest)
{
    queue<pi> q;
    dist[source.f][source.s] = 0;
    q.push(source);

    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();
        int i, j;
        i = cur.f;
        j = cur.s;
        if (cur.f == dest.f && cur.s == dest.s) {
            return dist[i][j];
        }
        if (!visited[cur.f][cur.s]) {
            visited[cur.f][cur.s] = true;
            
            if (i+2 <= 8 && j-1 >= 1) {
                q.push({i+2, j-1});
                dist[i+2][j-1] = dist[i][j] + 1;
            }

            if (i+2 <= 8 && j+1 <= 8) {
                q.push({i+2, j+1});
                dist[i+2][j+1] = dist[i][j] + 1;
            }

            if (i-2 >= 1 && j-1 >= 1) {
                q.push({i-2, j-1});
                dist[i-2][j-1] = dist[i][j] + 1;
            }

            if (i-2 >= 1 && j+1 <= 8) {
                q.push({i-2, j+1});
                dist[i-2][j+1] = dist[i][j] + 1;
            }

            // JOGADAS J

            if (j+2 <= 8 && i-1 >= 1) {
                q.push({i-1, j+2});
                dist[i-1][j+2] = dist[i][j] + 1;
            }

            if (j+2 <= 8 && i+1 <= 8) {
                q.push({i+1, j+2});
                dist[i+1][j+2] = dist[i][j] + 1;
            }

            if (j-2 >= 1 && i-1 >= 1) {
                q.push({i-1, j-2});
                dist[i-1][j-2] = dist[i][j] + 1;
            }

            if (j-2 >= 1 && i+1 <= 8) {
                q.push({i+1, j-2});
                dist[i+1][j-2] = dist[i][j] + 1;
            }
        }
    }
    return 0;
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    int ans;

    int xi, yi, xf, yf;
    while (cin >> s1 >> s2)
    {
        memset(visited, false, sizeof(visited));
        memset(dist, false, sizeof(dist));

        xi = (s1[0] - 'a') + 1;
        yi = s1[1] - '0';

        xf = (s2[0] - 'a') + 1;
        yf = s2[1] - '0';

        if (xi == xf && yi == yf) {
            ans = 0;
        } else {
            ans = bfs({xi, yi}, {xf, yf});
        }

        //cout << "(" << xi << ", " << yi << ") ";

        //cout << "(" << xf << ", " << yf << ")\n";

        cout << "To get from "<< s1 <<" to "<< s2 <<" takes "<< ans << " knight moves.\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome