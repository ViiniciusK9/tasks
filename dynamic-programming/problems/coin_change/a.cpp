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
const int MAX = int(500);

int memo[MAX];
vi v;

int solve(int k)
{
    if (k == 0)
        return 0;

    if (k < 0)
        return INF;

    if (memo[k]) return memo[k];

    int ans = INF;

    for (auto c : v)
    {
        ans = min(ans, solve(k-c) + 1);
    }
    return memo[k] = ans;
}

int dp_buttom_up(int k)
{
    memo[0] = 0;

    for (int i = 1; i <= k; i++){
        memo[i] = INF;
        for (auto c : v)
        {
            if (i-c >=0) {
                memo[i] = min(memo[i],memo[i-c] + 1);
            }
        }
    }

    return memo[k];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, k;
    cin >> k >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.pb(aux);
    }
    
    memset(memo, 0, sizeof(memo));
    int ans = solve(k);

    if (ans >= INF) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }

    memset(memo, 0, sizeof(memo));
    ans = dp_buttom_up(k);

    if (ans >= INF) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome