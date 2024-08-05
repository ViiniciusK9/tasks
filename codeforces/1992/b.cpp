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
        vi a;
        cin >> n >> k;
        int aux;

        int mx = INT_MIN;
        ll sum = 0;
        for (int i = 0; i < k; i++)
        {
            cin >> aux;
            mx = max(mx, aux);
            a.pb(aux);
        }
        ll ans = 0;
        bool f = false;
        for (int i = 0; i < k; i++)
        {
            if (a[i] == mx && f == false) {
                f = true;
            } else if (a[i] == 1){
                ans++;
            } else {
                ans += a[i] * 2 - 1;
            }
            
            
        }


        cout << ans << '\n';
        
        
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome