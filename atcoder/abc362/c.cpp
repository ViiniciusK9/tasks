#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll sum = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    ll x, y;
    vector<ii> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.pb({x, y});
        sum += x;
        sum1 += y;

        sum2 += (x + y) / 2;
    }

    DBG(sum2);

    if (sum <= 0 && sum1 >= 0)
    {
        cout << "Yes\n";
        sum = 0;
        sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            
        }
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome