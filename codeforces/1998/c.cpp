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
        ll n, k;
        cin >> n >> k;

        vector<ii> v(n);
        for (int i = 0; i < n; i++)
        {
            ll aux;
            cin >> aux;
            v[i].first = aux;
        }

        for (int i = 0; i < n; i++)
        {
            ll aux;
            cin >> aux;
            v[i].second = aux;
        }

        sort(v.begin(), v.end());

        /*
        for (int i = 0; i < n; i++)
        {

            cout << (i == 0 ? "" : " ") << v[i].first;
        }

        cout << '\n';

        for (int i = 0; i < n; i++)
        {

            cout << (i == 0 ? "" : " ") << v[i].second;
        }

        cout << '\n';

        */
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second == 1)
            {
                if (mx == -1)
                {
                    mx = i;
                }
                else if (v[i].first >= v[mx].first)
                {
                    mx = i;
                }
            }
        }

        if (mx != -1)
        {
            if (v[mx].first + k > v[n - 1].first)
            {
                int med = (n + 1) / 2;
                if (med == mx + 1)
                {
                    med = med;
                }
                else
                {
                    med--;
                }
                cout << (v[med].first + v[mx].first + k) << '\n';
            }
            else
            {
                int med = (n + 1) / 2;

                med-=2;
                ll valm = v[med].first;
                if (v[med].second == 1) {
                    if (med+1 < n-1) {
                        valm = min(v[med].first + k, v[med+1].first);
                    } else {
                        valm = v[med].first + k;
                    }
                } else {
                    
                }

                cout << valm + v[n - 1].first << '\n';
            }
        }
        else
        {
            int med = (n + 1) / 2;
            med--;
            cout << v[med].first + v[n - 1].first << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome