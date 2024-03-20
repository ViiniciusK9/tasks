#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t, a, b, c, ans;
    cin >> t;

    while (t--)
    {
        ans = 0;
        cin >> a >> b >> c;
        if (b%3 == 0 || ( 3 - b%3 ) <= c) {
            ans += a;
            ans += b/3;
            if (b%3 != 0) {
                ans++;
                c = c - ( 3 - b%3 );
            }
            ans += c/3;
            
            if ( c%3 != 0) ans++;
            cout << ans << '\n';
        } else {
            cout << "-1\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome