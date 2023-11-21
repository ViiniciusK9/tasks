#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, ans = 0, disponivel = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux > 0)
        {
            disponivel += aux;
        }     
        else 
        {
            if ((disponivel - abs(aux)) < 0)
            {
                ans += abs(disponivel - abs(aux));
                disponivel = 0;
            } else 
            {
                disponivel -= abs(aux);
            }

        }
    }
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome