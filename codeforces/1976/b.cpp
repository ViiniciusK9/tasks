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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux;
    vi a;
    vi b;
    cin >> t;

    while (t--)
    {
        a.clear();
        b.clear();
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            a.pb(aux);
        }

        for (int i = 0; i < n + 1; i++)
        {
            cin >> aux;
            b.pb(aux);
        }

        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += abs(a[i] - b[i]);
        }

        //DBG(ans);

        int val = b[n];
        int ind = 0;
        int qval = 1e9 + 19;
        int qve = -2;

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= val && b[i] <= val)
            {
                flag = true;
                break;
            }

            if (a[i] <= val && b[i] >= val)
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            ans++;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (abs(val - a[i]) < qval)
                {
                    qval = abs(val - a[i]);
                    ind = i;
                    qve = 0;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (abs(val - b[i]) < qval)
                {
                    qval = abs(val - b[i]);
                    ind = i;
                    qve = 1;
                }
            }

            if (qval == 0)
            {
                ans++;
            }
            else
            {
                ans += qval + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome