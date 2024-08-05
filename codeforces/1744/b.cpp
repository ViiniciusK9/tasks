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

    int t;

    cin >> t;
    int n, q;
    vi v;
    while (t--)
    {
        v.clear();
        cin >> n >> q;

        int aux;
        ll ans = 0;
        int q1, q2;
        q1 = q2 = 0;
        for (int i = 0; i < n; i++)
        {
            
            cin >> aux;

            ans += aux;
            if (aux % 2 == 0) {
                q1++;
            } else {
                q2++;
            }

            //v.pb(aux);
        }
        int tp, val;
        while (q--)
        {
            cin >> tp >> val;

            if (tp == 0) {

                ans += q1 * val;

                if (val % 2 == 0) {
                    q1 = q1;
                } else {
                    q2 += q1;
                    q1 = 0;
                }
            } else {
                ans += q2 * val;
                if (val % 2 == 0) {
                    q2 = q2;
                } else {
                    q1 += q2;
                    q2 = 0;
                }
            }
            cout << ans << '\n';
        }

        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome