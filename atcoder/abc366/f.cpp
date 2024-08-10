#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;


const int MAX = int(2e5+10);
int n, k;

bool use[MAX];
vi a(MAX);
vi b(MAX);

ll solve(ll q, ll mul) {
    if (q == k) {
        return 0;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (!use[i]) {
            use[i] = true;
            ans = max(ans, solve(q+1, a[i] * mul + b[i]) + a[i] * mul + b[i]);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    cout << solve(0, 1) << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome