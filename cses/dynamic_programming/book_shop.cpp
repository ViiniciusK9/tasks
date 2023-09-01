#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1123
#define INF 112345678

int n, x;

int price[MAX], pages[MAX];

int memo[1001][100001];

int solve(int w)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j < price[i])
            {
                memo[i][j] = memo[i-1][j];
            } else 
            {
                memo[i][j] = max(pages[i] + memo[i - 1][j - price[i]], memo[i-1][j]);
            }
        }
    }
    
    return memo[n][w];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }

    memset(memo, 0, sizeof(memo));

    cout << solve(x) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome