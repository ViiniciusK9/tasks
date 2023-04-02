#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

ll exp_bin(ll a, ll e, ll p) {
    if (e == 0) {
        return 1;
    }

    if (e & 1) {
        return (a * exp_bin(a, e-1, p)) % p; 
    }
    ll b = exp_bin(a, e/2, p);
    return (b * b) % p;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll b, p, m;

    while (cin >> b >> p >> m)
    {
        //cout << b << p << m << '\n';
        cout << exp_bin(b, p, m) << '\n';
    }
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome