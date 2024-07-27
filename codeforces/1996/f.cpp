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
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        vi a;
        vi b;
        ll n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            a.pb(aux);
        }

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            b.pb(aux);
        }

        priority_queue<ii> q;
        for (int i = 0; i < n; i++)
        {
            q.push({a[i], b[i]});
        }

        ll ans = 0;
        while (k >= 1 && !q.empty())
        {
            ii cur = q.top();
            // DBG(cur.first);
            // DBG(cur.second);
            q.pop();
            ii ne = {-1, -1};
            if (!q.empty())
            {
                ne = q.top();
            }

            if (ne.first == -1 || ne.first == 0)
            {
                ll qnt = abs(cur.first) / cur.second;

                
                qnt++;

                qnt = min(qnt, (ll)k);
                k -= qnt;
                if (cur.second == 1)
                {
                    ans += (qnt * (cur.first - (qnt - 1) + cur.first)) / 2;
                }
                else
                {
                    ans += qnt * cur.first - (qnt - 1) * cur.second;
                    cur.first = max((ll)0, cur.first - qnt * cur.second);
                }
            }
            else
            {
                ll qnt = abs(cur.first - ne.first) / cur.second;
                
                qnt++;
                qnt = min(qnt, (ll)k);
                k -= qnt;

                if (cur.second == 1)
                {
                    ans += (qnt * (cur.first - (qnt - 1) + cur.first)) / 2;
                    cur.first = max((ll)0, cur.first - qnt * cur.second);
                    q.push(cur);
                }
                else
                {
                    ans += qnt * cur.first - (qnt - 1) * cur.second;
                    cur.first = max((ll)0, cur.first - qnt * cur.second);
                    q.push(cur);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome