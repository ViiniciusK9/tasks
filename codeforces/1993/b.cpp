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

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vi v(n);
        ll p1 = 0, p2 = 0;
        ll mx = 0;
        ll mmx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];

            if (v[i] % 2 == 0) {
                p1++;
                mmx = max(mmx, v[i]);
            } else {
                mx = max(mx, v[i]);
                p2++;
            }
        }

        sort(v.begin(), v.end());


        if (p1 == 0 || p2 == 0) {
            cout << "0\n";
            continue;
        } else {
            if (mmx > mx) {
                ll ans = 0;
                for (int i = 0; i < v.size(); i++)
                {
                    if (v[i] % 2 == 0 && mx >= v[i]) {
                        ans++;
                        mx = max(mx, mx+v[i]);
                    } else if (v[i] % 2 == 0 && mx < v[i]) {
                        ans+=2;
                        mx = mx+mmx;
                    }
                }
                
                cout << ans << '\n';
            } else {
                cout << p1 << '\n';
            }
        }
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome