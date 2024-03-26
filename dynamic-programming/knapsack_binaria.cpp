#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 1123

typedef long long ll;

int memo[MAX][MAX];     // memoização
int value[MAX];         // valor
int weight[MAX];        // peso

// Implementação top-down
int knapsack(int w, int n)
{
    if (memo[w][n] != -1) return memo[w][n];
    if (w == 0 || n == 0) return memo[w][n] = 0;

    if (weight[n-1] > w)
    {
        return memo[w][n] = knapsack(w, n-1);
    }

    return memo[w][n] = max(knapsack(w, n-1), value[n-1] + knapsack(w - weight[n-1], n-1));
}


int dp[MAX][MAX];

// Implementação bottom-up
int knapsack(int w, int n)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= w; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weight[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
        }
    }

    return dp[w][n];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome