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
    vi x;
    vi a;

    while (t--)
    {
        cin >> n;
        a.clear();
        x.clear();

        for (int i = 0; i < n-1; i++)
        {
            cin >> aux;
            x.pb(aux);
        }

        a.push_back(501);
        for (int i = 0; i < n-1; i++)
        {
            a.push_back(a[i] + x[i]);
        }

        /*
        for (int i = 1; i < a.size(); i++)
        {
            cout << (a[i] % a[i-1]) << ' ';
        }
        cout << '\n';
        */

        cout << a[0];
        for (int i = 1; i < a.size(); i++)
        {
            cout <<" " << a[i];
        }
        cout << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome