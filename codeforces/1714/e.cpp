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
        int cnt = 0;
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 10 == 0)
            {
                cnt++;
            }
            else if (v[i] % 10 == 5)
            {
                v[i] += 5;
                cnt++;
            }
        }

        //DBG(cnt);

        if (cnt != n && cnt != 0)
        {
            cout << "No\n";
        }
        else if (cnt == n)
        {
            bool ans = true;
            for (int i = 0; i < n; i++)
            {
                if (v[i] != v[0]) {
                    ans = false;
                }
            }

            cout << (ans ? "Yes\n" : "No\n");
        }
        else
        {
            int p1 = 0, p2 = 0;
            for (int i = 0; i < n; i++)
            {
                int rep = 7;
                while (rep >= 0)
                {
                    v[i] += v[i]%10;
                    rep--;
                }
                while (v[i]%10 != 4)
                {
                    v[i] += v[i]%10;
                }
                //DBG(v[i]);
                //DBG(((v[i] - (v[i]%10)) % 100));

                if ((((v[i] - (v[i]%10)) % 100)/10) % 2 == 0)
                {
                    p1++;
                }
                else
                {
                    p2++;
                }
            }

            if (p1 == n || p2 == n) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome