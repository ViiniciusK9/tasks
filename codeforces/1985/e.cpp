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
    ll x, y, z, k, c, val;
    cin >> t;

    while (t--)
    {
        cin >> x >> y >> z >> k;
        ll maior = 0;
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (k % (i * j) == 0) {
                    c = k / (i * j);
                    val = (x-i+1)*(y-j+1)*(z-c+1);
                    if (val > maior) {
                        maior = val;
                    }
                }
            }
        }
        cout << maior << '\n';
        
    

    }
    



    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome