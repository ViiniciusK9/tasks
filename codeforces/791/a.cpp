#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int ans = 0;
    while (a <= b)
    {
        a *=3;
        b *=2;
        ans++;
    }
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome