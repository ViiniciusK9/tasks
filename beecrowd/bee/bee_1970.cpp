#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 102

int memo[MAX][60][60][60];
int d[MAX];
int k, n;

int dp(int i, int c1, int c2, int c3) {
    int ch1, ch2 = 0, ch3 = 0, ch4 = 0;                         // Estados
    if (i == n)
    {
        return 0;
    }

    if (memo[i][c1][c2][c3] != -1)
    {
        return memo[i][c1][c2][c3];
    }
    
    ch1 = dp(i+1, c1, c2, c3);                      // Escolheu não colocar a musica em nenhum cartucho
    if (d[i] <= c1)
        ch2 = dp(i+1, c1 - d[i], c2, c3) + d[i];    // Escolheu colcoar a musica no primeiro cartucho
    if (d[i] <= c2)
        ch3 = dp(i+1, c1, c2 - d[i], c3) + d[i];    // Escolheu colcoar a musica no segundo cartucho
    if (d[i] <= c3)
        ch4 = dp(i+1, c1, c2, c3 - d[i]) + d[i];    // Escolheu colcoar a musica no terceiro cartucho

    return memo[i][c1][c2][c3] = max(ch1, max(ch2, max(ch3, ch4)));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c[] = {0, 0, 0};

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    
    cin >> c[0] >> c[1] >> c[2];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, c[0], c[1], c[2]) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome