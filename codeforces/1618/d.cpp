#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }


        sort(v.begin(), v.end());

        ll ans = 0;
        int ind = -1;
        int qnt = k;
        for (int i = n-1; i >= 0; i-=2)
        {
            if (qnt == 0) {
                ind = i;
                break;
            } else {
                
                ans += v[i-1] / v[i];

                qnt--;
            }
        }

        for (int i = 0; i <= ind; i++)
        {
            ans += v[i];
        }

        //cout << ans << '\n';


        int l = (n-1)-2*k;
        int r = n-1;
        ll ans2 = 0;
        qnt = k;
        while (l < r && qnt > 0)
        {
            ans2 += v[l]/v[r];
            l++;
            r--;
            qnt--;
        }

        for (int i = 0; i < (n-1)-2*k; i++)
        {
            ans2 += v[i];
        }

        cout << min(ans, ans2) << '\n';

        
        
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome