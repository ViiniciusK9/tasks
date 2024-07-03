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

vi v1;
vi v2;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v1.pb(aux);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v2.pb(aux);
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome