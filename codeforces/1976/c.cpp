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

const int MAX = int(2e5 + 20);

array<int, MAX> pos;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, tam, aux;
    vi a;
    vi b;
    cin >> t;

    while (t--)
    {
        a.clear();
        b.clear();
        cin >> n >> m;
        tam = n + m + 1;
        ll sum_a = 0, sum_b = 0;
        for (int i = 0; i < tam; i++)
        {
            cin >> aux;
            sum_a += aux;
            a.pb(aux);
        }

        for (int i = 0; i < tam; i++)
        {
            cin >> aux;
            sum_b += aux;
            b.pb(aux);
        }

        if (m == 0)
        {
            for (int i = 0; i < tam; i++)
            {
                if (i == 0)
                {
                    cout << sum_a - a[i];
                }
                else
                {
                    cout << " " << sum_a - a[i];
                }
            }
            cout << '\n';
        }
        else if (n == 0)
        {
            for (int i = 0; i < tam; i++)
            {
                if (i == 0)
                {
                    cout << sum_b - b[i];
                }
                else
                {
                    cout << " " << sum_b - b[i];
                }
            }
            cout << '\n';
        }
        else
        {
            pos.fill(0);
            ll sa = 0, sb = 0;

            int _min, _q;

            if (m < n)
            {
                _min = m;
                _q = 1;
            }
            else
            {
                _min = n;
                _q = 2;
            }

            int p1 = 0, p2 = 0;

            for (int i = 0; i < (_min * 2); i++)
            {
                if ((a[i] > b[i] && p1 < _min) || p2 >= _min)
                {
                    sa += a[i];
                    p1++;
                    pos[i] = 1;
                }
                else
                {
                    sb += b[i];
                    p2++;
                    pos[i] = 2;
                }
            }

            DBG(sa);
            DBG(sb);

            ll sr = 0;

            for (int i = (_min * 2); i < tam; i++)
            {
                if (_q == 1)
                {
                    sr += a[i];
                }
                else
                {
                    sr += b[i];
                }
            }

            ll ans = 0;
            for (int i = 0; i < tam; i++)
            {
                ll sbc = sb;
                ll sac = sa;
                ll src = sr;
                if (i < (_min * 2))
                {
                    if (pos[i] == 1)
                    {
                        sac -= a[i];
                        for (int j = i + 1; j <= (_min * 2); j++)
                        {
                            if (a[j] > b[j] && pos[j] == 2)
                            {
                                sac += a[j];
                                sbc -= b[j];
                                sbc += b[_min * 2];
                                if (_q == 1)
                                {
                                    src -= a[_min * 2];
                                }
                                else
                                {
                                    src -= b[_min * 2];
                                }
                                break;
                            }
                            else if (pos[j] == 0)
                            {
                                sac += a[j];
                                if (_q == 1)
                                {
                                    src -= a[_min * 2];
                                }
                                else
                                {
                                    src -= b[_min * 2];
                                }
                                break;
                            } 
                        }
                    }
                    else
                    {
                        sbc -= b[i];
                        for (int j = i + 1; j <= (_min * 2); j++)
                        {
                            if (b[j] > a[j] && pos[j] == 1)
                            {
                                sbc += b[j];
                                sac -= a[j];
                                sac += a[_min * 2];
                                if (_q == 1)
                                {
                                    src -= a[_min * 2];
                                }
                                else
                                {
                                    src -= b[_min * 2];
                                }
                                break;
                            }
                            else if (pos[j] == 0)
                            {
                                sbc += b[j];
                                if (_q == 1)
                                {
                                    src -= a[_min * 2];
                                }
                                else
                                {
                                    src -= b[_min * 2];
                                }
                                break;
                            }
                        }
                    }
                    cout << (sbc + sac + src) << " ";
                }
                else
                {
                    if (_q == 1) {
                        cout << (sbc + sac + src - a[i]) << " ";
                    } else {
                        cout << (sbc + sac + src - b[i]) << " ";
                    }
                }
            }

            cout << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome