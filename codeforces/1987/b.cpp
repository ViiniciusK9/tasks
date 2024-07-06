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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

vi v;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        ll ans = 0;

        v.clear();
        int at;
        for (int i = 0; i < n; i++)
        {
            cin >> at;
            v.pb(at);
        }

        vi aux;
        for (int i = 1; i < n; i++)
        {
            if (v[i] < v[i-1]) {
                aux.pb(v[i-1] - v[i]);
                v[i] = v[i-1];
            }
        }

        sort(aux.begin(), aux.end());

        
        ll r = 0;

        for (int i = 0; i < aux.size(); i++)
        {
            ll fir = aux[i];
            fir -= r;
            ans += (aux.size() - i) * fir + fir;
            r += fir;
        }
        

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome