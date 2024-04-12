#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(2)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, b, r;
    cin >> a >> b;
    
    r = b - a;
    r = (r * 100) / a;
    cout << F(r) << "%" << endl;


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome