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

    int xa, xb, xc, ya, yb, yc;

    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    vector<double> v;

    v.pb(hypot(xa - xb, ya - yb));
    v.pb(hypot(xa - xc, ya - yc));
    v.pb(hypot(xc - xb, yc - yb));

    sort(v.begin(), v.end());

    if (hypot(v[1], v[0]) == v[2])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome