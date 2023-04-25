#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n, m, x, y;

    while (cin >> k)
    {
        cin >> n >> m;
        while (k--)
        {
            cin >> x >> y;
            if (x == n || x == m || y == n || y == m)
            {
                cout << "divisa\n";
            } else if (y > m) {
                if (x > n)
                {
                    cout << "NE\n";
                } else {
                    cout << "NO\n";
                }
                
            } else {
                if (x > n)
                {
                    cout << "SE\n";
                } else {
                    cout << "SO\n";
                }
            }
            
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome