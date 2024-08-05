#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define fi first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 2e5 + 10;

ll n, m;
ll v[MAX];

bool fu(ll qnt)
{
    ll sm = 0;
    for (int i = 0; i < n; i++)
    {
        sm += min(qnt, v[i]);
    }
    
    return sm <= m;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    ll mx = m / n;

    ll l = 1;
    ll r = 2e14;

    if (sum <= m)
    {
        cout << "infinite\n";
    }
    else
    {

        while (l <= r)
        {
            ll m = (l + r) / 2;

            bool ans = fu(m);

            if (ans) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        cout << r << '\n';

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome