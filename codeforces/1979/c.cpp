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
    int aux;
    while (t--)
    {
        v.clear();
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

        ll sum = 1;
        for (auto vi : v)
        {
            sum = sum * vi;
        }
        vector<ll> v2;
        ll qnt = 0;
        for (auto vi : v)
        {
            qnt += (sum / vi);
            v2.pb((sum / vi));
        }

        if (qnt < sum)
        {
            for (int i = 0; i < v2.size(); i++)
            {
                cout << (i == 0 ? "" : " ") << v2[i];
            }
            
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome