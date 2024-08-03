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


const int MAX = 4e5+10;
const int MOD = 1e9+7;

int pref[MAX], a[MAX], ts[MAX];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        string s1;
        cin >> s1;

        ll len = s1.size();
        ll n = len;
        memset(ts, 0, sizeof(ts));

        for (ll i = 0; i < len; i++)
        {
            a[i] = (s1[i] == '1' ? 1 : -1);
            pref[i+1] = pref[i] + a[i];
        }

        /* TLE
        ll ans = 0;
        for (ll i = 0; i <= n-1; i++)
        {
            for (ll j = i+1; j <= n; j++)
            {
                if (pref[i] == pref[j]) {
                    ans += ((i+1) * (n-j+1));
                    ans %= MOD;
                }
            }
        }
        */

        ll ans = 0;

        for (ll i = 0; i <= n; i++)
        {
            int p = pref[i];
            ans += (((ll)ts[p+n]) * (n-i+1));
            ans %= MOD;
            ts[p+n] += i+1;
            ts[p+n] %= MOD;
        }
        

        
        cout << ans << '\n';

        /*
        for (int i = 0; i <= len; i++)
        {
            cout << pref[i] << " ";
        }

        cout << "\n";

        */

        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome