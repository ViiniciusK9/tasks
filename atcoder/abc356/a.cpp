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


    int n, l, r;

    cin >> n >> l >> r;
    vi v;
    for (int i = 1; i < l; i++)
    {
        v.pb(i);
    }

    for (int i = r; i >= l; i--)
    {
        v.pb(i);
    }

    for (int i = r+1; i <= n; i++)
    {
        v.pb(i);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << (i == 0 ? "" : " ") << v[i];
    }
    cout << '\n';
    
    
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome