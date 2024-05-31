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

int m = 32, x;

int dp[40];

int solve(int i, int k, int ant)
{
    if (k == x) {
        return 1;
    }
    
    if (i >= 32) {
        return 0;
    }

    if (dp[i] != 0) {
        return 1;
    }

    if (ant == 0) {
        dp[i] = 0;

        int ans1 = solve(i+1, k, 0);
        int ans2 = solve(i+1, k-(ll(1)<<i), 1);
        int ans3 = solve(i+1, k+(ll(1)<<i), 1);

        if (ans1 == 1) {
            dp[i] = 2;
        } else if (ans2 == 1) {
            dp[i] = -1;
        } else if (ans3 == 1) {
            dp[i] = 1;
        }
        return dp[i];
        //return max(solve(i+1, k),solve(i+1, k-(ll(1)<<i)), solve(i+1, k+(ll(1)<<i)));
    }
    else {
        int ans1 = solve(i+1, k, 0);
        dp[i] = 2;
        return dp[i];
    }

}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int xaux;
    cin >> t;
    vector<int> v;

    while (t--)
    {
        cin >> x;
        v.clear();
        memset(dp, 0, sizeof(dp));
        xaux = x;

        bitset<32> a(x);

        cout << solve(0, 0, 0) << '\n';

        for (int i = 0; i < 32; i++)
        {
            cout << dp[i] << '\n';
        }
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome