#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


const int MAX = 1001;
const int MAX2 = 2001;


int n, t;

int tam[MAX];
int custo[MAX];
int memo[MAX2];

int dp(int l)
{
    int ans = 0;

    if (l < 0)
    {
        return INT_MIN;
    }

    if (l == 0)
    {
        return 0;
    }

    if (memo[l] != -1)
    {
        return memo[l];
    }
    

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp(l - tam[i]) + custo[i]);
    }
    
    return memo[l] = ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        cin >> tam[i] >> custo[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(t) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome