#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    long long m;
    while (1)
    {
        cin >> x >> m;
        if (x == 0 and m == 0) {
            break;
        }
        cout << m * x << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome