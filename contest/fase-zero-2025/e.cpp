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

    ll y, k;
    ll x = 1;

    cin >> y >> k;
    ll xa = 0;
    
    while (k--)
    {
        DBG(x);
        DBG(x - xa);
        xa = x;
        x = x + gcd(x, y);
        if (x - xa == y) {
            break;
        }
    }
    x = x + (y * k);
    cout << x << endl;
        DBG(x);
        DBG(x - xa);
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome