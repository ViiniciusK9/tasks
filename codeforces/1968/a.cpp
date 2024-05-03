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

vector<int> factors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, x;
    vi v;

    cin >> t;

    while (t--)
    {
        v.clear();
        cin >> x;
        //v = factors(x);

        int ans = 0;
        int res = 0;

        for (int i = 1; i < x; i++)
        {
            if (__gcd(x, i) + i > ans)
            {
                ans = __gcd(x, i) + i;
                res = i;
            }
        }

        cout << res << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome