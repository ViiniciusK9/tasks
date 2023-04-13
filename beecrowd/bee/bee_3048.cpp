#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, at, ant, aux, ans = 0;
    cin >> n;
    cin >> aux;
    n--;
    ant = aux;
    ans++;
    while (n--)
    {
        cin >> at;
        if (ant != at)
        {
            ans++;
            ant = at;
        }
    }
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome