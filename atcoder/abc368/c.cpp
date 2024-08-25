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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;

    ll t = 0;

    for (int i = 0; i < n; i++)
    {
        ll val = v[i];

        if (t == 3) {
            val -= 3;
            ans++;
            t = 0;
        } else if (t == 2) {
            val-=1;
            ans++;
            t = 3;

            if (val > 0) {
                val-=3;
                ans++;
                t = 0;
            } else {
                continue;
            }
        }

        if (val <= 0) {
            continue;
        }

        ll qnt = val / 5;

        if (val % 5 == 1) {
            ans += 3*qnt + 1;
            t=2;
        } else if (val % 5 == 2) {
            ans += 3*qnt + 2;
            t=3;
        } else if (val % 5 == 0) {
            ans += 3*qnt;
            t=0;
        } else {
            ans += 3*qnt + 3;
            t=0;
        }
    }

    cout << ans << '\n';
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome