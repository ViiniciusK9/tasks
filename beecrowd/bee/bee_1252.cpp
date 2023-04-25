#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 11234
int n, m;
bool comparacao(int a, int b) {
    if ((a % m) == (b % m))
    {
        if (a % 2 == 1 && b % 2 == 1)
        {
            return a > b;
        } else if (a % 2 == 0 && b % 2 == 0) {
            return a < b;
        } else {
            return a % 2 != 0;
        }
    }
    return (a % m) < (b % m);
}
/*
bool comparacao(int a, int b) {
    return a > b;
}
*/

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vet[MAX];
    while (cin >> n >> m)
    {
        cout << n  << " " << m << '\n';
        if (n == 0 && m == 0)
        {
            break;
        }
        
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i]; 
        }
        sort(vet, vet+n, comparacao);
        for (int i = 0; i < n; i++)
        {
            cout << vet[i] << '\n'; 
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome