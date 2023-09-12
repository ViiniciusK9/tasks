#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    cin >> n;
    while (n--)
    {
        cin >> aux;
        if (aux < 3) {
            cout << 0 << '\n';
        } else {
            aux = (aux - 1) / 2;
            cout << aux << '\n';
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome