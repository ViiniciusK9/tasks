#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p1, c1, p2, c2;
    cin >> p1 >> c1 >> p2 >> c2;
    
    int ans1 = p1 * c1;
    int ans2 = p2 * c2;

    if (ans1 == ans2)
    {
        cout << "0\n";
    } else if (ans1 > ans2) {
        cout << "-1\n";
    } else {
        cout << "1\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome