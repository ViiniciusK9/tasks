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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

ll manhattan(int n)
{

    ll ans = 0;

    int cn = n;

    for (int i = 1; i <= n; i++)
    {
        ans += abs(cn - i);
        //DBG(abs(cn - i));
        cn--;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;

    cin >> t;
    ll n, k;
    while (t--)
    {
        cin >> n >> k;

        if (k == 0)
        {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
            {
                cout << (i == 1 ? "" : " ") << i;
            }
            cout << '\n';
        }
        else
        {

            ll man = manhattan(n);
            DBG(man);
            if (man < k)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome