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
    vector<ll> v1;
    vector<ll> v2;
    vector<ll> v3;
    int n;
    while (t--)
    {
        v1.clear();
        v2.clear();
        v3.clear();
        cin >> n;
        ll aux;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            sum += aux;
            v1.pb(sum);
        }
        
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            sum += aux;
            v2.pb(sum);
        }

        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            sum += aux;
            v3.pb(sum);
        }

        int i = 0;
        int j = n-1;
        int a1,a2,b1,b2,c1,c2;
        
        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome