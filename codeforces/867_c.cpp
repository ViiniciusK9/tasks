#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    long long aux, ans;
    while (t--)
    {
        cin >> aux;
        ans = (4 * aux) + 1 + (((1 + (aux - 1)) * (aux -1)) / 2) + (((1 + (aux - 2)) * (aux -2)) / 2);
        cout << ans << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome