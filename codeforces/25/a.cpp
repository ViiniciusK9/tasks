#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, par, impar, qnt, aux;
    cin >> n;
    qnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux % 2 == 0) {
            qnt++;
            par = i +1;
        } else {
            impar = i+1;
        }
        
    }

    if (qnt == 1) {
        cout << par << '\n';
    } else {
        cout << impar << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome