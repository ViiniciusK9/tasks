#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, p, qnt, _case = 1;

    while (n)
    {
        map<int, int> vet;
        for (int i = 0; i < n; i++)
        {
            cin >> p >> qnt;
            qnt /= p;
            vet[qnt] = p;
        }
        cout << "Cidade# " << _case << ":\n";
        _case++;
        int aux = 0;
        for (auto &j : vet)
        {
            if (aux == 0)
            {
                cout << j.second << "-" << j.first << " ";
                aux = 1;
            } else {

            }
            
            
        }
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome