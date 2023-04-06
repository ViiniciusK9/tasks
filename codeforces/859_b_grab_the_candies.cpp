#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t, n, even = 0, odd = 0, element;
    cin >> t;
    while (t--)
    {
        even = odd = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> element;
            if (element % 2 == 0)
            {
                even += element;
            } else {
                odd += element;
            }
            
        }
        if (even > odd)
        {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome