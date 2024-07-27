#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define fi first
#define se second
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
        ll n, f, a, b;
        vi time;
        cin >> n >> f >> a >> b;

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            time.pb(aux);
        }

        int at = 0;
        ll consumo = 0;

        for (int i = 0; i < n; i++)
        {
            ll val = abs(at - time[i]) * a;
            if (val < b)
            {
                consumo += val;
            }
            else
            {
                consumo += b;
            }
            at = time[i];
        }

        if (consumo < f) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome