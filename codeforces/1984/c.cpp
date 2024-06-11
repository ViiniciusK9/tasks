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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(2e5+10);

int n;
ll memo[MAX];
ll memo2[MAX];
vi v;

ll solve(int i) {

    if (i == -1) {
        return 0;
    }

    if (memo[i] != 0) {
        return memo[i];
    }

    
    return memo[i] = max(solve(i-1) + v[i], abs(solve(i-1) + v[i]));
}

ll solve1(int i) {

    if (i == -1) {
        return 0;
    }

    if (memo2[i] != 0) {
        return memo2[i];
    }

    
    return memo2[i] = min(solve1(i-1) + v[i], abs(solve1(i-1) + v[i]));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int aux;
    while (t--)
    {
        v.clear();
        cin >> n;


        memset(memo, 0, sizeof(memo));
        memset(memo2, 0, sizeof(memo2));
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

    

        cout << max(solve(n-1), abs(solve1(n-1))) << '\n';
        
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome