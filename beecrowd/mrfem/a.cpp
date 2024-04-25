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

const int MAX = 262149;

int n, aux;
int memo[MAX];
vi v;

void solve() {
    for (int i = n; i >= 1; i--)
    {
        memo[i] = v[i];
        
        if (i*2 <= n && i*2+1 <= n) {
            memo[i] += max(memo[i*2], memo[(i*2)+1]);
        } else if (i*2 <= n) {
            memo[i] += memo[i*2];
        } else if (i*2+1 <= n) {
            memo[i] += memo[i*2+1];
        }
    }
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 1) {
        cin >> aux;
        cout << aux << '\n';
        return 0;
    }
    n = pow(2, n) -1;
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.PB(aux);
    }

    

    solve();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, memo[i]);
    }
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome