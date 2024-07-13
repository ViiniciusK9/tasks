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
    int n, k;

    while (t--)
    {
        vi v;
        cin >> n >> k;
        int aux;
        map<int, int> ma;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            ma[aux]++;
            v.pb(aux);
        }

        if (v[0] == v[n - 1] && ma[v[0]] >= k)
        {
            cout << "YES\n";
        }
        else if (v[0] != v[n - 1])
        {
            int p = 0;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == v[0]) {
                    sum++;
                }

                if (sum == k) {
                    p = i;
                    break;
                }
            }
            int sum2=0;
            for (int i = n-1; i > p; i--)
            {
                if (v[i] == v[n-1]) {
                    sum2++;
                }

                if (sum2 == k) {
                    break;
                }
            }

            if (sum2 == sum && sum == k) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        else
        {

            cout << "NO\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome