#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        if (a < b && b < c) {
            cout << "STAIR\n";
        } else if (a < b && b > c) {
            cout << "PEAK\n";
        } else {
            cout << "NONE\n";   
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome