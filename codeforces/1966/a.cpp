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
    int n, k, c;
    map<int, int> m;

    cin >> t;

    while (t--)
    {
        /* code */

        cin >> n >> k;
        m.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> c;
            m[c]++;
        }
        int deu = 0;
        if (k > n)
        {
            cout << n << '\n';
        }
        else
        {
            for (auto v : m)
            {
                if (v.second >= k)
                {
                    deu = 1;
                    break;
                }
            }
            if (deu == 1)
            {
                cout << k - 1 << '\n';
            }
            else
            {
                cout << n << '\n';
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome