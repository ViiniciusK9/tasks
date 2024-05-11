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

int pir[MAX][MAX];
int dp[MAX][MAX][2];

int tab[MAX][MAX];

int n;

ll solve(int i, int j, int d)
{

    if (i >= n)
    {
        return 0;
    }

    if (dp[i][j][d] != 0)
        return dp[i][j][d];

    if (d)
    {
        return dp[i][j][d] = pir[i][j] + max({solve(i + 1, j + 1, 0), (ll)0});
    }

    if (j == 0)
    {
        return dp[i][j][d] = pir[i][j] + max({solve(i + 1, j, 0), solve(i + 1, j + 1, 1), solve(i + 1, j, 0) + solve(i + 1, j + 1, 1), (ll)0});
    }

    return dp[i][j][d] = pir[i][j] + max({solve(i + 1, j + 1, 0), (ll)0});
}

ll solve2()
{
    tab[0][0] = pir[0][0];
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            if (j-1 >= 0) {
                tab[i][j] = max(pir[i][j] + tab[i-1][j] + tab[i][j-1], pir[i][j] + tab[i-1][j]);
            } else {
                tab[i][j] = pir[i][j] + tab[i-1][j]; 
            }
        }
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> pir[i][j];
            }
        }

        solve2();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << tab[i][j] << " ";
            }
            cout << '\n';
        }

        // cout << solve(0, 0, 0) << '\n';
        ll ans = solve(0, 0, 0);
        if (ans <= 0)
        {
            cout << "0\n";
        }
        else
        {
            cout << ans << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome