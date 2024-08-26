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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 1123;

array<ll, MAX> ve;
int n;

ll memo[MAX][MAX];

ll solve(int i, int t) {

    if (i == n) {
        return 0;
    }

    if (memo[i][t] != 0) return memo[i][t];


    return memo[i][t] = min( solve(i+1, t) + abs(ve[i] - ve[i+1]) , solve(i+1, i) + abs(ve[t] - ve[i+1]) );
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ve[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> ve[i];
    }
    
    ll ans = solve(0, 0);
    cout << ans << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome