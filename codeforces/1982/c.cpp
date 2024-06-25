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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int aux;
    ll n, l, r;
    vi v;
    while (t--)
    {
        v.clear();
        cin >> n >> l >> r;

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

        ll ans = 0;
        ll u = -1;
        for (int i = 0; i < n; i++)
        {
            if (u >= i) continue;
            ll sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += v[j];
                if (sum >= l && sum <= r) {
                    //DBG(sum);
                    ans++;
                    u = j;
                    break;
                } else if (sum > r) {
                    break;
                } else if (j == n-1 && sum < l) {
                    u = n-1;
                }

            }
            
        }
        
        cout << ans << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome