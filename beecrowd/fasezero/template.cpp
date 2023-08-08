#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "110\n";
    for (int i = 1; i <= 110; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 110; i >= 1; i--)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome