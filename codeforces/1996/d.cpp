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
        ll n, x;

        cin >> n >> x;

        ll ans = 0;

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= i && j * i <= n; j++)
            {
                if (i + j > x)
                {
                    break;
                }
                for (ll k = 1; k <= j; k++)
                {
                    if ((i + j + k > x) || (i * j + j * k + i * k > n))
                    {
                        break;
                    }
                    if (i == k && i == j)
                    {
                        ans += 1;
                    }
                    else if (k == j || j == i || k == i)
                    {
                        ans += 3;
                    }
                    else
                    {
                        ans += 6;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome