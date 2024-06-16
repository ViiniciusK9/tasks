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

    int t;

    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;

        ll sum = 0;
        ll ms = 0;
        ll msi = 0;
        for (int i = 2; i <= n; i++)
        {
            ll at = i;
            sum = 0;
            while (at <= n)
            {
                sum+=at;
                at+=i;
            }

            //DBG(i);
            //DBG(sum);

            if (sum > ms) {
                ms = sum;
                msi = i;
            }
            
            
        }

        cout << msi << '\n';
        

        

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome