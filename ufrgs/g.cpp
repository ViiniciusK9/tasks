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

ll combinacao(ll n)
{
    return n * (n - 1) * (n - 2) / 6;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> a;
    set<int> b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.insert(x);
        b.insert(y);
    }

    ll num = max(a.size(), b.size());

    if (num == 3)
    {
        cout << 3 << '\n';
    }
    else
    {
        cout << combinacao(num) << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome