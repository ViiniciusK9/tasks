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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(2 * n + 10);
    vector<ll> pref(2 * n + 10);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = n; i < 2 * n; i++)
    {
        a[i] = a[i - n];
    }

    for (int i = 0; i < 2 * n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
        pref[i+1] %= m;
    }

    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        
        cout << pref[i] << ' ';
        if (i < n)
        {
            if (pref[i] % m == 0)
            {
                ans++;
            }
        }
        else
        {
            
            if (pref[i] % m == 0)
            {
                ans++;
            }
        }
    }

    cout << '\n';

    DBG(ans);

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome