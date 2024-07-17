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

const int MAX = int(1e5 + 10);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        vector<ii> seg;
        vi query;
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;
            seg.pb({l, r});
        }

        int q;

        cin >> q;

        for (int i = 0; i < q; i++)
        {
            int c;
            cin >> c;

            query.pb(c);
        }
        array<int, MAX> pf1;
        array<int, MAX> aux_pf1;
        for (int i = 0; i < q; i++)
        {
            aux_pf1[query[i] - 1] = 1;
            pf1[query[i] - 1] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                pf1[i] = pf1[i - 1] + pf1[i];
            }
        }

        bool ans = false;
        for (auto sg : seg)
        {
            if (pf1[sg.second - 1] - pf1[sg.first - 1] + aux_pf1[sg.first - 1] > (sg.second - (sg.first - 1)) / 2)
            {
                ans = true;
                break;
            }
        }

        if (!ans)
        {
            cout << "-1\n";
            continue;
        }

        int l = 0, r = q - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            array<int, MAX> pf;
            array<int, MAX> aux_pf;
            for (int i = 0; i <= mid; i++)
            {
                aux_pf[query[i] - 1] = 1;
                pf[query[i] - 1] = 1;
            }

            for (int i = 0; i < n; i++)
            {
                if (i != 0)
                {
                    pf[i] = pf[i - 1] + pf[i];
                }
            }

            ans = false;
            for (auto sg : seg)
            {
                if (pf[sg.second - 1] - pf[sg.first - 1] + aux_pf[sg.first - 1] > ((sg.second - (sg.first - 1)) / 2))
                {
                    ans = true;
                    break;
                }
            }

            if (ans)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << l + 1 << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome