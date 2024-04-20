#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed << std::setprecision(1) << (x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, i, it, n_, i_;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        it = 0;
        i = n / 2;
        i += n % 2;
        if (k <= i)
        {
            cout << std::fixed << std::setprecision(0) << (2 * k - 1) * (pow(2, it)) << '\n';
            continue;
        }
        k = k - i;
        while (k >= 1)
        {
            n_ = n - i;
            i += n_ / 2;
            i_ = n_ / 2;
            i += n_ % 2;
            i_ += n_ % 2;
            it++;

            if (k <= i_)
            {
                cout << std::fixed << std::setprecision(0) << (2 * k - 1) * (pow(2, it)) << '\n';
                break;
            }
            k -= i_;
            if (i_ == 0)
            {
                cout << k << '\n';
                break;
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome