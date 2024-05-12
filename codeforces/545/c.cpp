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

const int INF = int(1e9+9);
const int MAX = int(1e5+4);



vector<pi> v;
int n, x, h;
int dp[MAX];
int de[MAX];


ll solve(int i, ll k)
{
    if (i == n) {
        return 0;
    }

    if (dp[i] != 0) return dp[i];

    if (de[i-1] == 0) {
        k = v[i-1].f;
    } else {
        k = v[i-1].f + v[i-1].s;
    }

    if (v[i].f - v[i].s > k) {
        de[i] = 0;
        return dp[i] = 1 + solve(i+1, v[i].f);
    } else if (i+1 <= n-1 && v[i].f + v[i].s < v[i+1].f) {
        ll ans = 0;
        de[i] = 1;
        ans = 1 + solve(i+1, v[i].f + v[i].s);
        de[i] = 0;
        ans = max(ans, solve(i+1, v[i].f));
        return dp[i] = ans;
    } else if (i+1 <= n-1) {
        return dp[i] = solve(i+1, v[i].f);
    } else if (i+1 == n) {
        return dp[i] = 1 + solve(i+1, k);
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> h;
        v.pb({x, h});
    }

    de[0] = 0;
    cout << 1 + solve(1, v[0].f) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome