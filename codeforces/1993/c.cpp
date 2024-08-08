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
        int n, k;
        cin >> n >> k;
        vi v(n);
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(mx, v[i]);
        }

        sort(v.begin(), v.end());
        bool ans = true;
        int at = 0;


        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';

        for (int i = 0; i < n-1; i++)
        {
            cout << k * (v[i] / k + abs(v[i] / k - mx / k)) + v[i] % k << " ";
            int val = k * (v[i] / k + abs(v[i] / k - mx / k)) + v[i] % k;
            if (val+1 >= mx+k) {
                ans = false;
            }
        }
        cout << '\n';
        DBG(ans);
        
        /*
        for (int i = 0; i < n; i++)
        {
            cout << v[i] / k << " ";
        }
        cout << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << v[i] % (k) << " ";
        }
        */
        cout << '\n';
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome