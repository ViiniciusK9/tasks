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

ll n, k;

bool comp(ll a, ll b) {
    return a%k < b%k;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), comp);
        ll ans = 0;
       
        int i= 0;
        int j=n-1;
        vi v;
        while (i < j)
        {
            if (a[i] % k + a[j] % k  >= k) {
                ans += (a[i] + a[j]) / k;
                i++;
                j--;
                if (i == j) {
                    v.pb(i);
                }
            } else {
                v.pb(i);
                i++;
                if (i == j) {
                    v.pb(i);
                }
            }
        }
        
        for (int i = 0; i < v.size(); i+=2)
        {
            ans += (a[v[i]] + a[v[i+1]])/k;
        }
        
        cout << ans  << '\n';
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome