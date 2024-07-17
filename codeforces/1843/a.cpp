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
    int n;
    cin >> t;

    while (t--)
    {
        /* code */

        cin >> n;

        vi v;

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            v.pb(aux);
        }

        sort(v.begin(), v.end());

        int i = 0;
        int j = n-1;
        int ans = 0;
        while (i < j)
        {
            ans += (v[j]-v[i]);
            j--;
            i++;
        }

        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome