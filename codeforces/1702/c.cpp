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
        int n, k;
        cin >> n >> k;

        map<int, ii> ma;

        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (ma.find(v[i]) == ma.end())
            {
                ma[v[i]] = {i, i};
            }
            else
            {
                ma[v[i]].first = min(ma[v[i]].first, i);
                ma[v[i]].second = max(ma[v[i]].second, i);
            }
        }

        for (int i = 0; i < k; i++)
        {
            int l, r;
            cin >> l >> r;

            if (ma.find(l) != ma.end() && ma.find(r) != ma.end())
            {

                if (ma[l].first < ma[r].second)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome