#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 2e5+4;

int memo[MAX];
int n;
vi v;

int solve(int i, bool pegou) {

    if (i >= n) return 0;

    if (memo[i] != 0) return memo[i];

    if (pegou) {
        return memo[i] = solve(i+v[i], pegou) + v[i];
    }

    return memo[i] = max(solve(i+1, false), solve(i+v[i], true) + v[i]);
}

void solve2() {
    for (int i = n-1; i >= 0; i--)
    {
        memo[i] = v[i];
        if (i+v[i] < n) {
            memo[i] += memo[i+v[i]];
        }
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, aux;

    cin >> t;
    while (t--)
    {
        memset(memo, 0, sizeof(memo));
        v.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.PB(aux);
        }

        solve2();
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = max(ans, memo[i]);
        }
        cout << ans <<'\n';
        
        
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome