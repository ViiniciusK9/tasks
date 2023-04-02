#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (aux & 1)
            {
                cout << (2 * (aux - 1)) + 1 << '\n';
            } else {
                cout << (2 * (aux - 2)) + 2 << '\n';
            }
            
        }
    }
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome