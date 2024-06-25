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

    int t;

    cin >> t;
    int x, y, k;
    while (t--)
    {
        cin >> x >> y >> k;

        if (x < y)
        {
            int diff = y - x;
            if (diff <= k)
            {
                x = 1;
                k -= diff;
                diff = y - 1;
                int rest = k % diff;
                x = 1 + rest;
                k = 0;
                // continue;
            }
            else
            {
                x += k;
                k = 0;
                // continue;
            }
        }

        while (k)
        {
            //DBG(x);
            //DBG(y);
            //DBG(k);
            if (x < y)
            {
                int diff = y - x;
                if (diff <= k)
                {
                    x = 1;
                    k -= diff;
                    diff = y - 1;
                    int rest = k % diff;
                    x = 1 + rest;
                    k = 0;
                    continue;
                }
                else
                {
                    x += k;
                    k = 0;
                    continue;
                }
            }
            x += 1;
            k--;

            /*
            if (x <= y)
            {
                x = (x + k) % y;

                k = 0;
                continue;
            }
            */

            if (x % y == 0)
            {
                while (x % y == 0)
                {
                    x = x / y;
                }
                // k--;
            }
            else
            {
                // k--;
                if ((x % y) + k >= y)
                {
                    k -= (y - (x % y)) - 1;
                    x += (y - (x % y)) - 1;
                }
                else
                {
                    x += k;
                    k = 0;
                }
            }
        }

        cout << x << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome