#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, ans, aux;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            ans += abs(aux);
        }
        cout << ans << '\n'; 
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome