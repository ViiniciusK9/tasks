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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        vi v;

        for (int i = 1; i <= n; i++)
        {
            if (i >= y && i <= x)
            {
                v.pb(1);
                // cout << (i == 1 ? "" : " ") << "1";
            }
            else
            {
                v.pb(-1);
                // cout << (i == 1 ? "" : " ") <<"-1";
            }
        }

        int val = abs(x - y) + 1;

        int val1 = n - y + 1;
        val1 = n - val1;

        DBG(val);
        DBG(val1);

        if (val < val1)
        {
            for (int i = 0; i < abs(val-val1); i++)
            {
                v[i] = 1;
            }
        }

        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome