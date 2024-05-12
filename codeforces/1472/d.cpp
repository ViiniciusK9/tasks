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

const int MAX = int(2e5+10);

int t, n, aux;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    cin >> t;

    while (t--)
    {
        cin >> n;
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
            
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) {
                if (v[i] % 2 == 0) {
                    ans += v[i];
                }
            } else {
                if (v[i] % 2 == 1) {
                    ans -= v[i];
                }
            }
        }

        //cout << ans << '\n';
        if (ans == 0) {
            cout << "Tie\n";
        } else if (ans > 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome