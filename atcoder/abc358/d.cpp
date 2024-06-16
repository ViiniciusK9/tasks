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

    int n, m;

    cin >> n >> m;

    vi a;
    vi b;
    int aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        a.pb(aux);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        b.pb(aux);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    int i = 0;
    int j = 0;
    while (j < b.size() && i < a.size())
    {
        if (a[i] >= b[j]) {
            ans += a[i];
            i++;
            j++;
        } else {
            i++;
        }
    }

    if (j == b.size()) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
    
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome