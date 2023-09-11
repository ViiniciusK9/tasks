#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(3)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int a, b, c;

    cin >> a >> b >> c;

    double p  = ((a + b + c) / 2.0);
    double ans =  p * (p - a) * (p - b) * (p - c);
    ans = sqrt(ans);

    cout << F(ans) << " m2"  <<'\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome