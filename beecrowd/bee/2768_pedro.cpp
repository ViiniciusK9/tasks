#include <bits/stdc++.h>

using namespace std;
const int INF = 1e7;
const int MAX = 101;

int n,m,q;
int a, b, c;
int u, v, w;

int g[MAX][MAX];
int kek[MAX][MAX][MAX];


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);



    while(cin >> n >> m){

        for (int i = 0; i < MAX; i++)
        {
            fill(g[i], g[i]+MAX, -1);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = ((j == i)? 0 : INF);
            }
        }
        /*

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            g[a][b] = c;
            g[b][a] = c;

        }
        */
        
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            g[u ][v ] = w;
            g[v ][u ] = w;
        }

        /*
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    g[i][j] = 0;
                }
                else if (g[i][j] != -1)
                {
                    g[i][j] = g[i][j];
                }
                else
                {
                    g[i][j] = INF;
                }
            }
        }
        */


        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    kek[i][j][k] = g[i][j];
                }
            }
        }


        cin >> q;
        
        
            /* code */
        for (int i = 0; i < q; i++)
        {
            /* code */
        
        
            cin >> a >> b >> c;
            cout << ((kek[a][b][c] == INF)? -1 : kek[a][b][c]) << endl;
        }
        
        
    }
        return 0;
}