#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (m > n)
        {
            cout << "NO\n";
        } else if (m == n) {
            cout << "YES\n";
        } else {
            
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome