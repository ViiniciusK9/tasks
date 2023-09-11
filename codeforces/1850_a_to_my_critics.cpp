#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;

        if (a + b >= 10 || a + c >= 10 || b + c >= 10) cout << "YES\n";
        else cout << "NO\n";
        
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome