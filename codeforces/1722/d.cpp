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

        string s1;
        cin >> s1;

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == 'R')
            {
                ans += (n - 1) - i;
            }
            else
            {
                ans += (i);
            }
        }

        int i = 0;
        int j = n - 1;
        vi res;
        while (i <= j)
        {
            if (s1[i] == 'L' && s1[j] == 'R')
            {
                if ((n - 1) - i > j)
                {
                    ans += (n - 1) - i;
                    ans -= i;
                    res.pb(ans);
                    i++;
                }
                else
                {
                    ans -= (n - 1) - j;
                    ans += j;
                    res.pb(ans);
                    j--;
                }
            }
            else if (s1[j] == 'R' && (n - 1) - j < j)
            {
                ans -= (n - 1) - j;
                ans += j;
                res.pb(ans);
                j--;
            }
            else if (s1[i] == 'L' && (n - 1) - i > i)
            {
                ans += (n - 1) - i;
                ans -= i;
                res.pb(ans);
                i++;
            }
            else if (s1[i] == 'R' && s1[j] == 'L')
            {
                i++;
                j--;
            }
            else if (s1[i] == 'R')
            {
                i++;
            }
            else if (s1[j] == 'L')
            {
                j--;
            }
        }

        if (res.size() < n)
        {
            while (res.size() < n)
            {
                res.pb(ans);
            }
        }

        //sort(res.begin(), res.end());

        for (int i = 0; i < res.size(); i++)
        {
            cout << (i == 0 ? "" : " ") << res[i];
        }

        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome