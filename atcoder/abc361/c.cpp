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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;
    int aux;
    vi v;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.pb(aux);
    }

    sort(v.begin(), v.end());

    int ans = 1e9+10;

    for (int i = 0; i <= k; i++)
    {
        //cout << "if: " << i << " is: " << n-1+i-k << '\n';
        int at = (v[n-1+i-k] - v[i]);

        ans = min(ans, at);
    }

    //ans = min(ans, at);
    //ans = min(ans, at);

    cout << ans << '\n';
    


    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome