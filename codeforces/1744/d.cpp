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
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;

            while (aux % 2 == 0)
            {
                ans++;
                aux = aux / 2;
            }
        }

        vector<int> v1;
        int qnt;
        for (int i = 2; i <= n; i += 2)
        {
            qnt = 0;
            aux = i;
            while (aux % 2 == 0)
            {
                qnt++;
                aux = aux / 2;
            }
            v1.pb(qnt);
        }

        sort(v1.begin(), v1.end());

        reverse(v1.begin(), v1.end());

        if (ans < n)
        {
            qnt = 0;
            for (auto v : v1)
            {
                qnt++;
                ans += v;
                if (ans >= n)
                {
                    cout << qnt << '\n';
                    break;
                }
            }

            if (ans < n)
            {
                
                cout << "-1\n";
                
            }
        }
        else
        {
            cout << "0\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome