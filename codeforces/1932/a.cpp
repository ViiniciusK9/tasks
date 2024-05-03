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

const int INF = int(1e9);

int t, n;
string s;

int memo[60];

/* TLE */
int solve(int i)
{
    if (i >= n)
        return 0;

    if (s[i] == '*')
        return 0;

    if (memo[i] != 0)
        return memo[i];

    if (s[i] == '.')
    {
        return memo[i] = max(solve(i + 1), solve(i + 2));
    }

    return memo[i] = 1 + max(solve(i + 1), solve(i + 2));
}

int solve2(int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '@')
        {
            memo[i] = 1;
            if (i + 2 < len)
            {
                memo[i] += max(memo[i + 1], memo[i + 2]);
            }
            else if (i + 1 < len)
            {
                memo[i] += memo[i + 1];
            }
        } else if (s[i] == '.') {
            if (i + 2 < len)
            {
                memo[i] += max(memo[i + 1], memo[i + 2]);
            }
            else if (i + 1 < len)
            {
                memo[i] += memo[i + 1];
            }
        }
    }
    return memo[0];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> s;
        memset(memo, 0, sizeof(memo));
        cout << solve2(n) << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome