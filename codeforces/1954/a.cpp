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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, k, qnt, r;
    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k;

        qnt = n / m;
        r = n%m;
        if (r >= 1) {
            r = r-1;
        }

        if ((qnt * (m-1) + r) <= k) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome