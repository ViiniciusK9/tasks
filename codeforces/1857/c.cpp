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
    vi a;
    vi b;
    int n, m;
    while (t--)
    {
        a.clear();
        b.clear();


        cin >> n;

        m = n * (n-1) / 2;
        int aux;
        
        for (int i = 0; i < m; i++)
        {
            cin >> aux;
            
            b.pb(aux);
        }
        int maior = 1e9;
        sort(b.begin(), b.end());
        for (int i = 0; i < m; i+=n)
        {
            n--;
            cout << (i == 0 ? "" : " ") << b[i];
        }
        cout << " " << maior;
        
        cout << '\n';

        

        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome