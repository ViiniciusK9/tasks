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
        int n,m;

        cin >> n >> m;

        vi v1, v2, v3;

        for (int i = 0; i < n; i++)
        {
            ll aux;
            cin >> aux;
            v1.pb(aux);
            //v3.pb(aux);
        }

        for (int i = 0; i < m; i++)
        {
            ll aux;
            cin >> aux;
            v2.pb(aux);
            v3.pb(aux);
        }

        sort(v1.begin(), v1.end());
        sort(v3.begin(), v3.end());
        reverse(v3.begin(), v3.end());
        /*
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }

        cout << '\n';

        for (int i = 0; i < v3.size(); i++)
        {
            cout << v3[i] << " ";
        }

        cout << '\n';
        */
        

        ll ans = 0;
        int i = 0;
        int i1= 0;
        int j = n-1;
        int j1 = v3.size()-1;
        while (i <= j)
        {
            //DBG(abs(v1[i] - v3[i1]));
            if (abs(v1[i] - v3[i1]) >= abs(v1[j] - v3[j1])) {
                ans += abs(v1[i] - v3[i1]);
                i++;
                i1++;
            } else {
                ans += abs(v1[j] - v3[j1]);
                j1--;
                j--;
            }
        }
        

        cout << ans << '\n';
        



        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome