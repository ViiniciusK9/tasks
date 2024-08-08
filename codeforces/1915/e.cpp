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
        int n;
        cin >> n;
        vector<ll> pref(n+1);

        for (int i = 0; i < n; i++)
        {
            ll aux;
            cin >> aux;
            if (i % 2 != 0) {
                aux = -aux;
            }
            pref[i+1] = pref[i] + aux;
        }
        bool ans = false;
        map<ll, int> ma;
        for (int i = 0; i <= n; i++)
        {
            ma[pref[i]]++;
           // cout << pref[i] << " ";
        }

        for (auto el : ma)
        {
            if (el.second >= 2) {
                ans = true;
            }
        }
        


        //cout << '\n';

        cout << (ans ? "YES\n" : "NO\n");
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome