#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int p;
vi v;

bool solve(ll k){
    ll sum = 0;
    for (auto i : v){
        sum += k/i;
    }
    return (sum >= p);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    

    cin >> n >> p;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.PB(aux);
    }

    ll l = 0;
    ll r = 1e17;
    ll mid;

    while (l<r)
    {
        mid = (l+r)/2;
        if (solve(mid)) {
            r = mid;
        } else {
            l = mid +1;
        }
    }
    
    cout << l << '\n';


    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome


