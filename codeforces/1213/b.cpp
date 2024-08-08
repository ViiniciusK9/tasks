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

    int t, n, aux;

    cin >> t;
    vi v;
    while (t--)
    {
        cin >> n;
        v.clear();


        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }
        int menor = int(1e9);
        int ans = 0;
        for (int i =n-1; i >= 0; i--)
        {
            if (v[i] < menor) {
                menor = v[i];
            } else if (v[i] > menor){
                ans++;
            }
        }

        cout << ans << '\n';
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome