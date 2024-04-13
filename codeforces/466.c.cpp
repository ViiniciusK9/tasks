#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

set<pi> s;
vector<int> v;
ll ans, n;

void solve(int i, int j, ll s1, ll s2, ll s3)
{
    if (s.find({i, j}) != s.end()) return;

    if (i > j || j < i || i == j) {
        return;
    }
    
    if (s1 == s2 && s2 == s3) {
        ans++;
        s.insert({i, j});
    }

    solve(i+1, j, s1+v[i+1], s2-v[i+1], s3);
    solve(i, j-1, s1, s2-v[j-1], s3+v[j-1]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll aux, sum = 0;
    ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (i != 0 && i != n-1) 
            sum += aux;
        v.PB(aux);
    }

    solve(0, n-1, v[0], sum, v[n-1]);

    cout << ans << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome