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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    ll n, m;
    cin >> q;
    set<ll> st;
    vi v;
    while (q--)
    {
        cin >> n >> m;

        if (n < m) {
            cout << "0\n";
            continue;
        }
        st.clear();
        v.clear();
        ll ans = 0;
        ll start = m;
        ll qnt = -1;
        ll siz = st.size();
        while (siz > qnt && start <= n)
        {
            st.insert(start%10);
            siz = st.size();
            v.pb(start%10);
            qnt++;
            start += m;
        }

        ll sum = 0;

        for (int i = 0; i < siz; i++) {
            sum+=v[i];
        }

        qnt = n / m;

        ans = (qnt / siz) * sum;
        ll uu = qnt%siz;
        for (ll i = 0; i < uu; i++) {
            ans+=v[i];
        }

        

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome