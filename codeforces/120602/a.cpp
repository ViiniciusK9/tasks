#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s[0] == 'a')
        {
            cout << "YES\n";
        } else if (s[2] == 'c')
        {
            cout << "YES\n";
        }else if (s[1] == 'b')
        {
            cout << "YES\n";
        } else 
        {
            cout << "NO\n";
        }
        
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome