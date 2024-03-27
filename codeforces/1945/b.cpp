#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int t, a, b, m;

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> m;

        cout << ((m/a) + 1  + (m/b) + 1) << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome