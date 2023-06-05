#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 3000012

int n, m;
int vet[26];
int memo[1000012];

int dp_rec(int w) {
    if (w < 0)
    {
        return MAX;
    }
    if (w == 0)
    {
        return 0;
    }
    if (memo[w] != -1) return memo[w];

    int ans = MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp_rec(w - vet[i]) + 1);
    }
    
    return memo[w] = ans;
}

int dp_lin(int w) {
    memo[0] = 0;
    
    for (int i = 1; i <= m; i++)
    {
        memo[i] = MAX;
        for (int k = 0; k < n; k++)
        {
            if (vet[k] <= i)
            {
                memo[i] = min(memo[i], memo[i-vet[k]] + 1);
            }
        }
    }
    
    return memo[w];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
        }
        
        memset(memo, -1, sizeof(memo));
        sort(vet, vet+n);
        reverse(vet, vet+n);
        //cout << dp_rec(m) << '\n';
        cout << dp_lin(m) << '\n';
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome