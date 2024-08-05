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

deque<int> mat[123];

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

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                int aux;
                cin >> aux;
                mat[i].pb(aux);
            }
        }

        vi p;

        for (int i = 0; i < n; i++)
        {
            map<int, int> ma;

            for (int j = 0; j < n; j++)
            {
                if (!mat[j].empty())
                {
                    ma[mat[j].front()]++;
                }
            }

            int maior = 0;
            int val = 0;
            for (auto el : ma)
            {

                if (el.second > maior)
                {
                    maior = el.second;
                    val = el.first;
                }
            }

            for (int j = 0; j < n; j++)
            {
                if (!mat[j].empty())
                {
                    if (mat[j].front() == val)
                    {
                        mat[j].pop_front();
                    }
                }
            }

            p.pb(val);
        }

        bool fir = true;
        for (auto el : p)
        {
            cout << (fir ? "" : " ") << el;
            fir = false;
        }

        cout << '\n';

        for (int i = 0; i < n; i++)
        {
            mat[i].clear();
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome