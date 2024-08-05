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

    int t;

    cin >> t;
    
    while (t--)
    {
        vector<ll> v;
        ll n;
        ll sum = 0;
        cin >> n;
        ll aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            sum += aux;
            v.pb(sum);
        }

        ll med = sum / n;

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i]/(i+1) >= med) {
                continue;
            } else {
                flag = false;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome