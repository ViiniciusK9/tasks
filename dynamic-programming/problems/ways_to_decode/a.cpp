#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(1e7);

int memo[MAX];

int dp[MAX];

int n;
string s;

int wtd_security(int i)
{
    if (memo[i] != 0)
        return memo[i];

    if (i == n)
        return 1;

    if (s[i] == '0')
        return 0;

    if ((i + 1) < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
        return memo[i] = wtd_security(i+1) + wtd_security(i+2);

    return memo[i] = wtd_security(i+1);
}

int wtd_tab()
{
    if (s[0] == '0') {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    dp[0] = 1;
    dp[1] = int(s[1] != '0') + int(s[0] == '1' || (s[0] == '2' && s[1] <= '6'));

    for (int i = 2; i < n; i++) {
        if (s[i] != '0') {
            dp[i] += dp[i-1];
        }

        if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            dp[i] += dp[i-2];
        }
    }

    return dp[n-1];
}

int wtd_tab_optimization_memory()
{
    if (s[0] == '0') {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    int dp;
    int before_prev_dp = 1;
    int prev_dp = int(s[1] != '0') + int(s[0] == '1' || (s[0] == '2' && s[1] <= '6'));

    for (int i = 2; i < n; i++) {
        dp = 0;
        if (s[i] != '0') {
            dp += prev_dp;
        }

        if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            dp += before_prev_dp;
        }

        before_prev_dp = prev_dp;
        prev_dp = dp;
    }

    return prev_dp;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    n = s.length();

    memset(memo, 0, sizeof(memo));
    cout << wtd_security(0) << '\n';

    cout << wtd_tab() << '\n';

    cout << wtd_tab_optimization_memory() << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome