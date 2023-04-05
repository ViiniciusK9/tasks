#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, quant = 0;
    cin >> n;

    quant += n / 100;
    n = n % 100;
    quant += n / 20;
    n = n % 20;
    quant += n / 10;
    n = n % 10;
    quant += n / 5;
    n = n % 5;
    quant += n;
    cout << quant << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome