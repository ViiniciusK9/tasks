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

ll mex(vector<ll> const &A)
{
    set<ll> b(A.begin(), A.end());

    ll result = 0;
    while (b.count(result))
        ++result;
    return result;
}

ll gauss(ll x)
{
    return (x * (x + 1)) / 2;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> a(n);
        vector<ll> d(n, 0);

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ll aux;
            for (int j = 0; j < k; j++)
            {
                cin >> aux;
                a[i].pb(aux);
            }
        }

        for (int i = 0; i < n; i++)
        {
            ll maior = 0;
            a[i].pb(0);

            for (int j = 0; j < 3; j++)
            {
                maior = mex(a[i]);
                d[i] = max(d[i], maior);
                a[i].back() = maior;
            }
        }

        ll mmex = *max_element(d.begin(), d.end());

        if (mmex > m)
        {
            cout << (1 + m) * mmex << endl;
            continue;
        }
        else
        {
            ll sum = mmex * (mmex + 1);
            ll l = gauss(m);
            l -= gauss(mmex);
            cout << (ll)sum + l << endl;
        }
    }
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome