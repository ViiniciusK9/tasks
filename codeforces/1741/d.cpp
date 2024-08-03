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
        vi v;
        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int aux;
            cin >> aux;
            v.pb(aux);
        }

        if (m == 1)
        {
            cout << "0\n";
            continue;
        }

        bool ans = true;
        ll qnt = 0;

        int ml = 2;
        while (ml <= m)
        {
            DBG(ml);
            for (int i = 0; i < m; i += ml)
            {
                bool vl = true;
                for (int j = i; j < i + ml; j++)
                {
                    if (v[j] < v[j + 1] && abs(v[j] - v[j + 1]) == 1)
                    {
                        continue;
                    }
                    else
                    {
                        vl = false;
                        break;
                    }
                }

                if (vl)
                {
                    continue;
                }
                else
                {
                    DBG(i);
                    DBG(i + ml);
                    sort(v.begin() + i, v.begin() + i + ml);
                    for (int j = i; j < i + ml; j++)
                    {
                        if (v[j] < v[j + 1] && abs(v[j] - v[j + 1]) == 1)
                        {
                            continue;
                        }
                        else
                        {
                            vl = false;
                            break;
                        }
                    }

                    if (vl)
                    {
                        qnt++;
                    }
                    else
                    {
                        ans = false;
                    }
                }
            }

            

            ml *= 2;
        }



        cout << (ans ? "True\n" : "False\n");
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome