#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, ans, aux;
    cin >> n;

    while (n--)
    {
        cin >> a >> b;
        aux = abs(a-b);
        ans = (aux / 10) + ((aux % 10 != 0) ? 1 : 0); 
        cout << ans << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome