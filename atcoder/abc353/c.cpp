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

const int M = int(1e8);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, aux, ant;
    vector<ll> v;
    vector<ll> sum_a;
    

    cin >> n;
    ll ac = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.pb(aux);
        ac += aux;
        sum_a.pb(ac);
    }
    
    for (int i = 1; i <= n-1; i++)
    {
        //DBG((sum_a[n-1] - sum_a[i-1]));
        sum += ((n - i) * v[i-1]) + (sum_a[n-1] - sum_a[i-1]) % M;
    }


    // WA - TEST 5             :(
    cout << sum << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome