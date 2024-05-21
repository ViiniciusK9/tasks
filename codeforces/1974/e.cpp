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

const int MAX = int(2e8);

vector<pi> v;
int m, n, x;

map<bitset<55>, ll> ma;

ll memo[55];

ll solve(int i, bitset<55> b)
{
    if (i == m) return 0;

    if (memo[i] != 0) return memo[i];

    ll val = i*x;

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == 1) {

        }
    }
    


    if (v[i].first <= ) {
        // pegar
        b |= ll (1) << i;
        ll ans1 = solve(i+1, b)+ v[i].second;
        b |= ll (1) << i;
        ll ans2 = 



        return memo[i] = max(solve(i+1, tam - v[i].f + x) + v[i].second, solve(i+1, tam+x));
    }

    return memo[i] = solve(i+1, tam+x);
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b;

    cin >> t;

    while (t--)
    {
        v.clear();
        dp.fill(0);
        previ.fill(0);
        memset(memo, 0, sizeof(memo));
        cin >> m >> x;
        n = m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            v.pb({a, b});
        }

        cout << bottom_up_optimization_memory(m-1) << '\n';
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome