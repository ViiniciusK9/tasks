#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int N = 1e5;

int memo[N];


int dp(int n)
{
    if (n == 1) return 0;

    int &ans = memo[n];

    if (ans != -1) return ans;

    ans = INT_MAX;

    if (n % 2 == 0)
    {
        ans = min(ans, dp(n/2));
    }
    if (n % 3 == 0)
    {
        ans = min(ans, dp(n/3));
    }
    ans = min(ans, dp(n-1));
    ans += 1;
    return ans;
}

int _dp(int n)
{
    if (n == 1) return 0;

    if (memo[n] != -1) return memo[n];

    int ans = INT_MAX;

    if (n % 2 == 0)
    {
        ans = min(ans, _dp(n/2));
    }
    if (n % 3 == 0)
    {
        ans = min(ans, _dp(n/3));
    }
    ans = min(ans, _dp(n-1));
    ans += 1;
    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << _dp(n) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome