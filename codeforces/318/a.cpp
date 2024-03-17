#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;

    cin >> n >> k;

    long long mid = n/2;
    mid += n%2;
    
    if (k > mid) {
        k = k-mid;
        cout << k*2 << '\n';
    } else {
        cout << k*2-1 << '\n';
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome