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
        vi a;
        vi b;
        vi c;
        int n;
        cin >> n;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            a.pb(aux);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            b.pb(aux);
        }

        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx,a[i]-b[i] );
            c.pb(a[i]-b[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (c[i] == mx) ans++;
            //cout << c[i] << " ";
        }
        cout << ans << '\n';
        int au = ans;
        for (int i = 0; i < n; i++)
        {
            if (c[i] == mx){
                cout << (ans == au ? "" : " ") << i+1;
                au--;
            }
        }
        
        cout << '\n';


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome