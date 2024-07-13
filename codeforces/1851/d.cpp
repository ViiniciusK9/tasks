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
    int n;
    while (t--)
    {
        vector<ll> v;
        cin >> n;
        ll aux;
        ll ant = 0;
        set<ll> st;

        ll ult = (n * (n + 1)) / 2;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

        //DBG(ult);

        if (v[n - 1] != ult)
        {
            v.pb(ult);

            ant = 0;
            st.insert(v[0]);
            for (int i = 0; i < v.size(); i++)
            {
                if (i != 0)
                {
                    st.insert(v[i] - ant);
                    // cout << v[i] - ant << " ";
                }

                ant = v[i];
            }

            if (st.size() == n) {
                int f = 1;
                bool ans = true;
                for (auto el : st)
                {
                    if (f == el) {
                        f++;
                    } else {
                        ans = false;
                    }
                }

                if (ans) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
                


            } else {
                cout << "NO\n";
            }
            

        }
        else
        {
            map<ll, int> ma;

            ant = 0;
            ma[v[0]]++;
            for (int i = 0; i < v.size(); i++)
            {
                if (i != 0)
                {
                    ma[v[i] - ant]++;
                    // cout << v[i] - ant << " ";
                }

                ant = v[i];
            }
            

            cout << "NO\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome