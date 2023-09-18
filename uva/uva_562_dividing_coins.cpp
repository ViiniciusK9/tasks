#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int coins[110];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, m;
    cin >> t;
    while (t--)
    {
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> coins[i];
        }
        
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome