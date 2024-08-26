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
        int n;
        cin >> n;

        string aux;
        vector<string> v;

        for (int i = 0; i < n - 2; i++)
        {
            string in;
            cin >> in;
            v.pb(in);
            aux.push_back(in[0]);
            aux.push_back(in[1]);
        }

        string ans;

        if (n == 3)
        {

            ans.push_back(v[v.size() - 1][0]);
            ans.push_back(v[v.size() - 1][1]);
            ans.push_back(v[v.size() - 1][1]);
            cout << ans << '\n';
            continue;
        }

        bool re = true;
        for (int i = 0; i < n - 3; i++)
        {
            if (v[i][1] != v[i + 1][0])
            {
                ans.push_back(v[i][0]);
                ans.push_back(v[i][1]);
                re = false;
            }
            else
            {
                ans.push_back(v[i][0]);
            }
        }

        ans.push_back(v[v.size() - 1][0]);
        ans.push_back(v[v.size() - 1][1]);

        if (re)
        {
            ans.push_back(v[v.size() - 1][1]);
        }

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome