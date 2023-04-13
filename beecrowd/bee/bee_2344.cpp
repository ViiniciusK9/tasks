#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "E\n";
    } else if (n < 36) {
        cout << "D\n";
    } else if (n < 61) {
        cout << "C\n";
    } else if (n < 86) {
        cout << "B\n";
    } else {
        cout << "A\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome