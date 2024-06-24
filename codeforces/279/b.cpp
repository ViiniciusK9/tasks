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

    int n, t;

    cin >> n >> t;
    vi v;
    vector<ll> vs;
    int aux;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        sum += aux;
        v.pb(aux);
        vs.pb(sum);
    }

    if (sum <= t)
    {
        cout << n << '\n';
    }
    else
    {
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            int l, r;
            ll inicio = (i == 0 ? 0 : vs[i - 1]);
            l = i;
            r = n - 1;
            int achou = 0;
            int m;
            while (l <= r)
            {
                m = (l + r) / 2;
                ll val = vs[m] - inicio;
                if (val > t)
                {
                    r = m - 1;
                }
                else if (val == t)
                {
                    achou = 1;
                    break;
                }
                else
                {
                    l = m + 1;
                }
            }

            if (achou == 1)
            {
                int qnt = m - i + 1;
                ans = max(ans, qnt);
            }
            else
            {
                if (l != i)
                {
                    int qnt = l - i;
                    ans = max(ans, qnt);
                }
                else
                {
                    if (vs[l] - inicio <= t)
                    {
                        int qnt = 1;
                        ans = max(ans, qnt);
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome