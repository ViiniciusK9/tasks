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

    int n;
    cin >> n;
    int ans = 0;
    if (n >= 8) {
        n-=8;
        ans++;
    }
    if (n >= 4) {
        n-=4;
        ans++;
    }
    if (n >= 2) {
        n-=2;
        ans++;
    }
    if (n >= 1) {
        n-=1;
        ans++;
    }
    cout << ans << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome