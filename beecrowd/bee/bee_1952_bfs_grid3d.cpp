#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 112
#define INF 112345678

struct pos {
    int i, j, k;
    pos() {}
    pos(int _i, int _j, int _k) : i(_i), j(_j), k(_k) {}
};

int m, n, l, dist[MAX][MAX][MAX];

int di[] = {2, 1, -2, -1, 2, 1, -2, -1, 2, 0, -2, 0, 2, 0, -2, 0, 1, 0, -1, 0, 1, 0,-1, 0};
int dj[] = {1, 2, 1, 2, -1, -2, -1, -2, 0, 2, 0, -2, 0, 2, 0, -2, 0, 1, 0, -1, 0, 1, 0,-1};
int dk[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, -1, -1, -1, -1, 2, 2,  2, 2, -2, -2,-2,-2};

// 24 movimentos do cavalo em um grid 3d
// 2 1 -2 -1  2  1 -2 -1 2 0 -2  0  2  0 -2  0 1 0 -1  0  1  0 -1  0
// 1 2  1  2 -1 -2 -1 -2 0 2  0 -2  0  2  0 -2 0 1  0 -1  0  1  0 -1
// 0 0  0  0  0  0  0  0 1 1  1  1 -1 -1 -1 -1 2 2  2  2 -2 -2 -2 -2


int bfs(pos s, pos t) {
    int i, j, k;
    queue<pos> q;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            for (k = 1; k <= l; k++) {
                dist[i][j][k] = INF;
            }
        }   
    }

    dist[s.i][s.j][s.k] = 0;
    q.push(s);
    while (!q.empty())
    {
        pos u = q.front();
        q.pop();
        for (int mov = 0; mov < 24; mov++)
        {
            i = u.i + di[mov]; j = u.j + dj[mov]; k = u.k + dk[mov];
            if (i >= 1 && i <= n && j >= 1 && j <= m && k >= 1 && k <= l && dist[i][j][k] == INF)
            {
                dist[i][j][k] = dist[u.i][u.j][u.k] + 1;
                q.push(pos(i, j, k));
            }
        }
    }
    return dist[t.i][t.j][t.k];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pos s, t;
    cin >> n >> m >> l;
    cin >> s.i >> s.j >> s.k;
    cin >> t.i >> t.j >> t.k;
    cout << bfs(s, t) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome