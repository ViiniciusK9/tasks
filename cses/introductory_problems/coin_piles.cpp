#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a > 2*b or b > 2*a) {
            cout << "NO\n";
        } else if (a % 3 == 2 && b % 3 == 1 || a % 3 == 1 && b % 3 == 2 || a % 3 == 0 && b % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome