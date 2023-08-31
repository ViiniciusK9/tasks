#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 1e5;

int memo[MAX];

int rodCutting(int n, int prices[])
{
    if (n == 0) return 0;

    if (memo[n] != -1) return memo[n];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, prices[i] + rodCutting(n-i, prices));
    }
    
    return memo[n] = ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int prices[n];

    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }

    memset(memo, -1, sizeof(memo));
    
    cout << rodCutting(n, prices) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome