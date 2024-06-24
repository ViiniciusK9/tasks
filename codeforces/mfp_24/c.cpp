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
    for (int x = 1; x <= n; x++)
    {
        if (n % x == 0)
        {
            f.push_back(x);
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

    int a, b;

    cin >> a >> b;

    int diff = abs(a - b);

    vi v = factors(a);
    int mi = 10000000;
    for (auto vi : v)
    {
        // DBG(a / vi);
        if ((a / vi) >= diff)
        {
            mi = min(mi, (a / vi));
        }
    }
    cout << mi << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome