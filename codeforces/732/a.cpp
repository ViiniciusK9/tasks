#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, r;
    cin >> k >> r;

    int i = 1;
    while (true)
    {
        if ((i * k) % 10 == 0 ) break;

        if (((i * k) % 10) - r == 0) break;
        i++;
    }

    cout << i << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome