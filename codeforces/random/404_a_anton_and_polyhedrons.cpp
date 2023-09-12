#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "Tetrahedron")
        {
            ans += 4;
        } else if (s == "Icosahedron") {
            ans += 20;
        } else if (s == "Cube") {
            ans += 6;
        } else if (s == "Octahedron") {
            ans += 8;
        } else if (s == "Dodecahedron") {
            ans += 12;
        }
        
    }
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome