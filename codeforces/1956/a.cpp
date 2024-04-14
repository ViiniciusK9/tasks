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

    int n, t, k, q, m, aux;

    cin >> t;

    while (t--)
    {

        cin >> k >> q;
        cin >> aux;
        m = aux;
        for (int i = 1; i < k; i++)
        {
            cin >> aux;
            m = min(m, aux);
        }

        for (int i = 0; i < q; i++)
        {
            cin >> aux;
            if (i == q - 1)
            {

                if (aux < m)
                {
                    cout << aux;
                }
                else
                {
                    cout << m - 1;
                }
            }
            else
            {
                if (aux < m)
                {
                    cout << aux << ' ';
                }
                else
                {
                    cout << m - 1 << ' ';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome