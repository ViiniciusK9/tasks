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
typedef pair<ll, ll> pi;
typedef pair<ll, pi> pii;

const int MAX = int(2e5 + 10);

int arr[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    ll h, n;
    vi a;
    vi c;
    while (t--)
    {
        a.clear();
        c.clear();
        cin >> h >> n;
        ll aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            a.pb(aux);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            c.pb(aux);
        }

        priority_queue<pii> pq;

        ll vida = h;
        ll ans = 0;

        while (vida > 0)
        {
            if (ans == 0)
            {
                ans++;
                for (int i = 0; i < n; i++)
                {
                    vida -= a[i];
                    pq.push({-(ans+c[i]), {a[i], c[i]}});
                }
            }
            else
            {

                pii cur = pq.top();
                pq.pop();

                //DBG(cur.first);

                if (abs(cur.first) <= ans)
                {
                    vida -= cur.second.first;
                    cur.first = -(ans + cur.second.second);
                    pq.push(cur);
                }
                else
                {
                    ans = abs(cur.first);
                    vida -= cur.second.first;
                    cur.first = -(ans + cur.second.second);
                    pq.push(cur);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome