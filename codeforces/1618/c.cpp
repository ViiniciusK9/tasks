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
        int n;
        cin >> n;
        vi v(n);
        vi par;
        vi impar;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i % 2 == 0)
            {
                impar.push_back(v[i]);
            }
            else
            {
                par.push_back(v[i]);
            }
        }

        ll fimpar = impar[0];

        for (int i = 1; i < impar.size(); i++)
        {
            fimpar = gcd(fimpar, impar[i]);
        }

        ll fpar = par[0];

        for (int i = 1; i < par.size(); i++)
        {
            fpar = gcd(fpar, par[i]);
        }

        if (fpar != fimpar)
        {
            if (max(fpar, fimpar) == 2)
            {
                int cnp = 0;
                int cni = 0;
                for (int i = 0; i < n; i++)
                {
                    if (i%2 == 0) {
                        cnp += v[i]%2;
                    } else {
                        cni += v[i]%2;
                    }
                }

                if ((cnp == impar.size() && cni == 0) || (cnp == 0 && cni == par.size())) {
                    cout << max(fpar, fimpar) << '\n';
                } else {
                    cout << "0\n";
                }
            }
            else
            {
                cout << max(fpar, fimpar) << '\n';
            }
        }
        else
        {
            cout << "0\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome