#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if ((n+1) % 3 == 0 || (n-1) % 3 == 0)
        {
            cout << "First\n";
        } else
        {
            cout << "Second\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome