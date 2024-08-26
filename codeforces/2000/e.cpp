#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair
#define all(x) x.begin(), x.end()

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
        int n, m, k;
        cin >> n >> m >> k;
        int w;
        cin >> w;
        vector<ll> v(w);

        for (int i = 0; i < w; i++)
        {
            cin >> v[i];
        }

        sort(all(v));

        vector<ll> ans;


        for (int i = 1; i <= n/2; i++)
        {
            for (int j = 1; j <= m/2; j++)
            {
                ans.pb(i*j);
            }
            
        }
        
        
        
        ll res = 0;

        sort(all(ans));

        int ja= ans.size()-1;
        int jv = v.size()-1;
        while (ja >= 0 && jv >= 0)
        {
            res += ans[ja]*v[jv];
            ja--;
            jv--;
        }

        cout << res << '\n';
        
        


        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome