#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, a, b;

    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        /* code */

        if (a * 2 < b)
        {
            cout << n * a << '\n';
        }
        else
        {
            cout << (n / 2 * b) + (n % 2 * a) << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome