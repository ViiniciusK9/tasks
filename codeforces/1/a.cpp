#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, a, ni = 0, mi = 0;
    cin >> n >> m >> a;

    ni = n / a;
    if (ni * a < n) ni++;

    mi = m / a;
    if (mi * a < m) mi++;

    cout << (mi * ni) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome