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

const int MAX = int(2e5 + 10);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        ll n, m;
        vi f;
        vi qnt;
        cin >> n >> m;
        map<int, ll> ma;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;

            f.pb(aux);
        }

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;

            qnt.pb(aux);
        }

        for (int i = 0; i < n; i++)
        {
            ma[f[i]] += qnt[i];
        }

        ll ans = 0;
        for (auto el : ma)
        {

            if (ma.find(el.first + 1) != ma.end())
            {
                ii ot = {el.first + 1, ma[el.first + 1]};

                ll x = el.first;
                ll y = ot.first;
                ll a = el.second;
                ll b = ot.second;

                ll mx = 0;

                
                ll max_x = min(a, m / x);

                for (int i = max_x; i >= 1; i--)
                {
                    ll cost_x = i * x;

                    ll remaining_coins = m - cost_x;

                    ll max_y = min(b, remaining_coins / y);

                    ll total_petals = i * x + max_y * y;
                    mx = max(mx, total_petals);

                    if (remaining_coins < y) {
                        break;
                    }
                }
                

                ans = max(ans, mx);
            }

            if (ma.find(el.first - 1) != ma.end())
            {
                ii ot = {el.first - 1, ma[el.first - 1]};

                ll x = el.first;
                ll y = ot.first;
                ll a = el.second;
                ll b = ot.second;

                ll mx = 0;

                ll max_x = min(a, m / x);

                for (int i = max_x; i >= 1; i--)
                {
                    ll cost_x = i * x;

                    ll remaining_coins = m - cost_x;

                    ll max_y = min(b, remaining_coins / y);

                    ll total_petals = i * x + max_y * y;
                    mx = max(mx, total_petals);

                    if (remaining_coins < y) {
                        break;
                    }
                }
                

                ans = max(ans, mx);
            }

            if (el.second >= 1)
            {
                ii ot = {0, 1};

                ll x = el.first;
                ll y = ot.first;
                ll a = el.second;
                ll b = ot.second;

                ll mx = 0;

                ll max_x = min(a, m / x);

                for (int i = max_x; i >= 1; i--)
                {
                    ll cost_x = i * x;

                    ll remaining_coins = m - cost_x;

                    ll max_y = min(b, remaining_coins / y);

                    ll total_petals = i * x + max_y * y;
                    mx = max(mx, total_petals);

                    if (remaining_coins < y) {
                        break;
                    }
                }

                
                ans = max(ans, mx);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome