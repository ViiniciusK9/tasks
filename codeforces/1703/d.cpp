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
        vector<string> a;
        set<string> st;

        for (int i = 0; i < n; i++)
        {
            string s1;
            cin >> s1;
            a.pb(s1);
            st.insert(s1);
        }

        vi ans;

        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 1; j < a[i].size(); j++)
            {
                auto fir = a[i].substr(0, j);
                auto las = a[i].substr(j);

                //DBG(fir);
                //DBG(las);

                if (st.count(fir) && st.count(las))
                {
                    flag = true;
                    ans.pb(1);
                    break;
                }
            }

            if (!flag)
            {
                ans.pb(0);
            }
        }

        for (auto el : ans)
        {
            cout << el;
        }

        cout << '\n';
        
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome