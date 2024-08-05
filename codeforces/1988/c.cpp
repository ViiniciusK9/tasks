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
        ll n;
        cin >> n;

        bitset<64> a = n;

        set<ll> st;
        st.insert(n);

        for (int i = 0; i < 64; i++)
        {
            if (a[i] == 1)
            {
                bitset<64> b = (1 << i);
                ll num = ((ll)1 << i);
                if (n - num >= (ll)1)
                {
                    st.insert(n - num);
                }
            }
        }

        cout << st.size() << '\n';
        bool fir = true;
        for (auto el : st)
        {
            cout << (fir == true ? "" : " ") << el;
            fir = false;
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome