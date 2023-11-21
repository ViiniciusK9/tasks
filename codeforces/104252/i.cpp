#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 101

typedef pair<int, int> pi;

int dl[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };


int ng[MAX][MAX], vis[MAX][MAX];

int busca_larg(int l, int c, pi pos_ini) {

    for (int i = 0; i < l; i++)
    {
        memset(vis[i], 0, sizeof(vis[i]));
    }
    int ans = 0;
    queue<pi> fila;

    vis[pos_ini.first][pos_ini.second] = 1;



    fila.push(pos_ini);
    ans++;

    while (!fila.empty()) {
        auto pos = fila.front();
        fila.pop();

        for (int i = 0; i < 4; i++) {
            pi pos_prox = { pos.first + dl[i], pos.second + dc[i] };

            if ((pos_prox.first < 0) || (pos_prox.first >= l)) {
                continue;
            }

            if ((pos_prox.second < 0) || (pos_prox.second >= c)) {
                continue;
            }

            if (ng[pos_prox.first][pos_prox.second] < ng[pos.first][pos.second]) {
                continue;
            }

            if (!vis[pos_prox.first][pos_prox.second]) {
                vis[pos_prox.first][pos_prox.second] = 1;
                
                fila.push(pos_prox);
                ans++;
            }

        }
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, c;
    cin >> l >> c;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> ng[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans = max(ans, busca_larg(l, c, {i, j}));    
        }
    }
    
    cout << ans << '\n';



    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome