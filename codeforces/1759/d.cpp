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
        int n, m;

        cin >> n >> m;

        double x = 10 / n;

        ll r = (n*m);

        ll mx = 0;

        ll at = 1;
        ll val = 10;
        while (val <= r)
        {
            //DBG(val);
            mx = max(mx, (((r/val)) * val));

            
            val *=10;
        }
        
        cout << mx << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome