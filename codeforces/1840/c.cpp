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
        int n, k, q;
        cin >> n >> k >> q;
        vi v;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            v.pb(aux);
        }

        ll ans = 0;
        ll tam = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= q)
            {
                tam++;
            }
            else
            {
                if (tam >= k)
                {
                    ans += ((tam - k + 1) * (tam - k + 2)) / 2;
                    tam = 0;
                }
                else
                {
                    tam = 0;
                }
            }
        }

        if (tam >= k)
            ans += ((tam - k + 1) * (tam - k + 2)) / 2;

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome