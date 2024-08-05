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

    int t;
    cin >> t;

    while (t--)
    {
        ll l, r, x, a, b;

        cin >> l >> r >> x;
        cin >> a >> b;

        if (a == b)
        {
            cout << "0\n";
            continue;
        }

        if ((abs(a - r) < x && abs(a - l) < x) || (abs(b - r) < x && abs(b - l) < x))
        {
            cout << "-1\n";
        }
        else
        {
            if (abs(a - b) >= x)
            {
                cout << "1\n";
            }
            else
            {
                if ((abs(a-r) >= x && abs(b-r) >= x) || (abs(a-l) >= x && abs(b-l) >= x)) {
                    cout << "2\n";
                } else {
                    cout << "3\n";
                }
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome