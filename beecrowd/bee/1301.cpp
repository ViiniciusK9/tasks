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

vi v(112345);
vi qp(112345);
vi qn(112345);
vi qz(112345);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, aux;
    int a, b;
    char c;
    cin >> n >> k;
    int z, p, ne;
    z = p = ne = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux > 0)
            aux = 1;
        else if (aux < 0)
            aux = -1;

        if (aux == 0)
        {
            qz[i] = z + 1;
            qp[i] = p;
            qn[i] = ne;
            z++;
        }
        else if (aux == 1)
        {
            qp[i] = p + 1;
            qn[i] = ne;
            qz[i] = z;
            p++;
        }
        else
        {
            qn[i] = ne + 1;
            qp[i] = p;
            qz[i] = z;
            ne++;
        }
        v[i] = aux;
    }

    while (k--)
    {
        cin >> c >> a >> b;
        // DBG(c);
        // DBG(a);
        // DBG(b);

        if (c == 'C')
        {
            if (v[a - 1] > 0 && b > 0 || v[a - 1] < 0 && b < 0 || v[a - 1] == 0 && b == 0)
            {
                continue;
            }
            else
            {
                if (b > 0)
                {
                    b = 1;
                }
                else if (b < 0)
                {
                    b = -1;
                }

                v[a - 1] = b;
            }
        }
        else
        {
            if ((qz[b - 1] - qz[a - 1]) == 0)
            {
                if ((qn[b - 1] - qn[a - 1]) % 2 == 1)
                {
                    cout << "-";
                }
                else
                {
                    cout << "+";
                }
            }
            else
            {
                cout << "0";
            }
        }
    }

    cout << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome