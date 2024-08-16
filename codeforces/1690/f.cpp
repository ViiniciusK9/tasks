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
        int n;
        cin >> n;
        vi v(n);
        string s1;
        cin >> s1;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i]--;
        }

        vi a(n);

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int start = i;
            int au = i;
            cnt++;
            while (v[au] != start)
            {
                au = v[au];
                cnt++;
            }

            a[i] = cnt;
        }
        ll l = 1;
        for (int i = 0; i < n; i++)
        {
            l = lcm(l, a[i]);
        }
        
        cout << l << '\n';

    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome