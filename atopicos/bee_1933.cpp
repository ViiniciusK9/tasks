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
    if (a >= b) {
        cout << a << '\n';
    } else {
        cout << b << '\n';
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome