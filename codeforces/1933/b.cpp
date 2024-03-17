#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, a, aa, aux, sum;
    cin >> t;
    while (t--)
    {
        a = aa = sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (a == 0 && (aux % 3) == 1) a = 1;
            if (aa == 0 && (aux % 3) == 2) aa = 1;
            sum += aux;
        }
        if (sum % 3 == 0) cout << 0 << '\n';
        else if (sum % 3 == 2) cout << 1 << '\n';
        else if (sum % 3 == 1 && a == 1) cout << 1 << '\n';
        else cout << 2 << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome