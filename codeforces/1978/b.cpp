#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
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

    ll t;
    cin >> t;
    ll n, a, b;
    while (t--)
    {
        cin >> n >> a >> b;

        if (a >= b)
        {
            cout << (a * n) << '\n';
        }
        else
        {
            ll dif = abs(b - a);
            //DBG(dif);
            dif = min(dif, n);
            //DBG(dif);
            ll ans;
            
            ans = ((dif) * ((b - dif)+1 + b)) / 2;
            ans += (n - (dif)) * a;
            
            
            cout << ans << '\n';
            
                
            
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome