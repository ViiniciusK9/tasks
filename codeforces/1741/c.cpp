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

ll pref[2123];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            ll aux;
            cin >> aux;
            pref[i + 1] = pref[i] + aux;
        }

        vi v;

        for (int i = 1; i < n; i++)
        {
            if (pref[n] % pref[i] == 0)
            {
                v.pb(i);
            }
        }

        int mi = n;
        for (auto el : v)
        {
            ll val = pref[el];

            int ant = el;
            ll sum;
            bool test = true;
            int mx = el;
            for (int i = el+1; i <= n; i++)
            {
                
                sum = pref[i] - pref[ant];

                if (sum == val)
                {
                    mx = max(mx, abs(i - ant));
                    ant = i;
                }
                else if (sum > val)
                {
                    test = false;
                    break;
                } else if (i == n && sum != val) {
                    test = false;
                }
            }

            if (test && mx != INT_MIN)
            {
                mi = min(mx, mi);
            }
        }
        if (mi == INT_MAX)
        {
            cout << n << '\n';
        }
        else
        {
            cout << mi << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome