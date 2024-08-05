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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n, x;
    vi v;
    while (t--)
    {
        v.clear();
        cin >> n >> x;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

        unordered_map<ll, ll> count;
        ll ans = 1;

        for (int i = 0; i < n; ++i) {
            bool ns = false;
            for (const auto& [key, value] : count) {
                if (key != 0 && x % key == 0 && x / key == v[i]) {
                    ns = true;
                    break;
                }
            }
            if (ns) {
                ans++;
                count.clear();
            }
            count[v[i]]++;
        }
        
        cout << ans << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome