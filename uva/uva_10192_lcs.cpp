#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;
string s1, s2;

int memo[110][110];

int dp (int i1, int i2)
{
    // base case
    if (i1 == s1.size()) return 0;
    if (i2 == s2.size()) return 0;
    if (memo[i1][i2] != -1) return memo[i1][i2];

    int ans;

    if (s1[i1] == s2[i2]) ans = dp(i1 + 1, i2 +1) + 1;
    else ans = max(dp(i1 +1, i2), dp(i1, i2 + 1));

    return  memo[i1][i2] = ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (getline(cin, s1) && getline(cin, s2) && s1 != "#")
    {
        memset(memo, -1, sizeof(memo));
        cout << "Case #" << t << ": you can visit at most " << dp(0, 0) << " cities.\n";
        t++;
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome