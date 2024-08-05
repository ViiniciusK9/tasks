#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
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

    ll n, x, y;
    cin >> n >> x >> y;
    vi a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ll s1 = 0, s2 = 0;
    ll mi = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        s1 += a[i];
        if (s1 > x)
        {
            mi = min(mi, (ll)(i + 1));
        }
    }

    if (s1 <= x)
    {
        mi = min(mi, (ll)(n));
    }

    for (int i = 0; i < n; i++)
    {
        s2 += b[i];
        if (s2 > y)
        {
            mi = min(mi, (ll)(i + 1));
        }
    }

    if (s2 <= y)
    {
        mi = min(mi, (ll)(n));
    }

    cout << mi << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome