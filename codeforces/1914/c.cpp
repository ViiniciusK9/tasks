#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
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

        vi a(n);
        vi b(n);
        vi pref(n+1);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pref[i+1] = pref[i] + a[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        ll exp = 0;
        ll mx = 0;

        for (int i = 0; i < n; i++)
        {
            ll q1 = i+1;
            mx = max(mx, b[i]);
            ll q2 = k-q1;
            if (q2 < 0 || i+1 > n) {
                break;
            }
            exp = max(pref[q1] + mx*q2, exp);
        }

        cout << exp << '\n';
        



    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome