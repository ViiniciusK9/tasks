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

    ll m;

    cin >> m;

    ll i = 0;
    ll val = 1;

    m = m * 1000000;

    while((val / 8) < m) {
        i++;
        val <<= 1;
    }

    cout << i << endl;

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome