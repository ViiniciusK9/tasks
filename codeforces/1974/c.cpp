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

    int t, n;

    map<int, map<int, vector<int>>> m1;
    map<int, map<int, vector<int>>> m2;
    map<int, map<int, vector<int>>> m3;

    cin >> t;

    while (t--)
    {
        m1.clear();
        m2.clear();
        m3.clear();
        cin >> n;
        int f1, s1, at;
        cin >> f1 >> s1;
        for (int i = 0; i < n - 2; i++)
        {
            cin >> at;

            m1[f1][s1].pb(at);
            m2[s1][at].pb(f1);
            m3[f1][at].pb(s1);

            // cout << "(" << f1 << " " << s1 << " " << at << ") \n";
            f1 = s1;
            s1 = at;
        }

        set<int> aux;
        ll ans = 0;

        for (auto vi : m1)
        {
            // DBG(vi.first);
            for (auto vj : m1[vi.first])
            {
                aux.clear();
                if (m1[vi.first][vj.first].size() > 1)
                {
                    for (auto vi : m1[vi.first][vj.first])
                    {
                        aux.insert(vi);
                    }

                    if (aux.size() > 1)
                    {
                        if (aux.size() == m1[vi.first][vj.first].size()) {
                            ans += m1[vi.first][vj.first].size() -1;
                        } else {
                            ans += m1[vi.first][vj.first].size() -1;
                        }
                    }
                }
            }
        }

        for (auto vi : m2)
        {
            // DBG(vi.first);
            for (auto vj : m2[vi.first])
            {
                aux.clear();
                if (m2[vi.first][vj.first].size() > 1)
                {
                    for (auto vi : m2[vi.first][vj.first])
                    {
                        aux.insert(vi);
                    }

                    if (aux.size() > 1)
                    {
                        if (aux.size() == m2[vi.first][vj.first].size()) {
                            ans += m2[vi.first][vj.first].size() -1;
                        } else {
                            ans += m2[vi.first][vj.first].size() -1;
                        }
                    }
                }
            }
        }

        for (auto vi : m3)
        {
            // DBG(vi.first);
            for (auto vj : m3[vi.first])
            {
                aux.clear();
                if (m3[vi.first][vj.first].size() > 1)
                {
                    for (auto vi : m3[vi.first][vj.first])
                    {
                        aux.insert(vi);
                    }

                    if (aux.size() > 1)
                    {
                        if (aux.size() == m3[vi.first][vj.first].size()) {
                            ans += m3[vi.first][vj.first].size() -1;
                        } else {
                            ans += m3[vi.first][vj.first].size() -1;
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome