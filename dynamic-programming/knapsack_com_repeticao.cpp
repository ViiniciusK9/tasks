#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 1123

typedef long long ll;

int value[MAX];         // valor
int weight[MAX];        // peso

int dp[MAX];
// Implementação bottom-up
int knapsack(int w, int n)
{
    memset(dp, 0, sizeof(dp));

    for (int j = 1; j <= w; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (weight[i-1] <= j)
                dp[j] = max(dp[j], dp[j-weight[i-1]] + value[i-1]);
        }
    }

    return dp[w];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome