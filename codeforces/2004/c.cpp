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

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                ll diff = abs(a[i] - a[i - 1]);
                if (k >= diff)
                {
                    k -= diff;
                    a[i] += diff;
                }
                else
                {
                    a[i] += k;
                    k -= k;
                    break;
                }
            }
        }

        ll ans = 0;
        ll ans2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans += a[i];
            }
            else
            {
                ans2 += a[i];
            }
        }

        cout << ans - ans2 << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome