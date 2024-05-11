#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(1e7);
ll dp [MAX][5];



ll solve(int n)
{
    for (int i = 0; i < 5; i++){
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] +  dp[i-1][1] +  dp[i-1][2] +  dp[i-1][3] +  dp[i-1][4]; 
        dp[i][1] = dp[i-1][1] +  dp[i-1][2] +  dp[i-1][3] +  dp[i-1][4];
        dp[i][2] = dp[i-1][2] +  dp[i-1][3] +  dp[i-1][4];
        dp[i][3] = dp[i-1][3] +  dp[i-1][4];
        dp[i][4] = dp[i-1][4];
    }

    ll ans = 0;
    for (int i = 0; i < 5; i++){
        ans += dp[n-1][i];
    }
    return ans;
}

/*
    Existe uma formula para esse problema que utiliza combinatoria.
*/
ll count(ll n){
    return (n+4)*(n+3)*(n+2)*(n+1)/(ll)24;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    cout << solve(n) << '\n';

    cout << count(n) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome