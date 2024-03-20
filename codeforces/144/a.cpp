#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, in, ax, fi, ini, axi, ans;
    cin >> n;
    cin >> fi;
    in = ax = fi;
    ini = axi = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> aux;
        if (aux <= in) {
            in = aux;
            ini = i;
        }

        if (aux > ax) {
            axi = i;
            ax = aux;
        }
    }

    ans = (abs(axi - 0) + abs(ini - (n-1)));

    if (ini < axi) ans--;

    cout << ans << '\n';    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome