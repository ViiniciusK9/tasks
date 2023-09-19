#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int coins[110];
int total, n;
int memo[110][50010];

// a ideia é pegar a menor diferença entre sum - (total - sum), meio que subtraindo duas vezes do total e pegando a menor diferença possivel

int dp(int i, int sum)
{
    if (i == n) return abs(sum - (total - sum));

    if (memo[i][sum] != -1) return memo[i][sum];

    int ans;
    
    ans = min(dp(i+1, sum), dp(i+1, sum+ coins[i]));

    return memo[i][sum] = ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        total = 0;
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
            total += coins[i];
        }

        cout << dp(0, 0) << '\n';
    }
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome