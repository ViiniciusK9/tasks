#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;

    cin >> a >> b >> c;

    if (a == 1) {
        if (c == 1) {
            cout << a + b + c << '\n';
        } else {
            cout << (a + b) * c << '\n';
        }
    } else if (b == 1) {
        if ( a < c) {
            cout << (a + b) * c << '\n';
        } else {
            cout << a * (b + c) << '\n';
        }
    } else if (c == 1) {
        cout << a * (b+c) << '\n';
    } else {
        cout << a * b * c << '\n';
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome