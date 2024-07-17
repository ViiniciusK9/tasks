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
        ll n,k;
        cin >> n >> k;


        k = min(k, (ll)30);

        ll ans = min(n, ((ll)1 << k) - 1) + 1;
        
        

        cout << ans << '\n';
        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome