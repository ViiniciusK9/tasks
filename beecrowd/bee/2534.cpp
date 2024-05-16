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

    int n, q, aux;
    vi v;
    while (cin >> n >> q)
    {
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        for (int i = 0; i < q; i++)
        {
            cin >> aux;
            cout << v[aux-1] << '\n';
        }
        
           
    }
    

    
    return 0;
}

