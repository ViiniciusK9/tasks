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
typedef pair<ll, ii> iii;
typedef pair<ll, iii> iiii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<iiii> v;

    for (int i = 0; i < n; i++)
    {
        ll t, m, c;
        cin >> t >> m >> c;

        v.pb({t, {m, {c, i + 1}}});
    }

    sort(v.begin(), v.end());

    deque<iiii> q;
    ll tm = 0;
    ll ans = 0;
    vi res;
    for (int i = 0; i < n; i++)
    {

        iiii at = v[i];

        if (q.empty())
        {
            q.push_back(at);
        }
        else
        {
            if (at.s.s.f == 0)
            {
                q.push_back(at);
            }
            else
            {

                while (!q.empty() && max(tm, q.front().f) + q.front().s.f <= at.f)
                {
                    tm = max(tm, q.front().f) + q.front().s.f;
                    q.pop_front();
                }

                if (!q.empty())
                {
                    res.pb(q.front().s.s.s);
                    tm = at.first;
                    q.pop_front();

                    q.push_front(at);
                    ans++;
                }
                else
                {
                    q.push_back(at);
                }
            }
        }
    }

    cout << ans << '\n';
    bool fr = false;
    for (auto el : res)
    {
        cout << (fr == false ? "" : " ") << el;
        fr = true;
    }

    
    cout << '\n';
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome