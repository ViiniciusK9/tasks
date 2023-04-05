#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vet[1234];
    int vet_aux[1234];

    int n, tam, num, resp;
    cin >> n;
    while (n--)
    {
        resp = 0;
        cin >> tam;
        for (int i = 0; i < tam; i++)
        {
            cin >> num;
            vet[i] = num;
            vet_aux[i] = num;
        }
        sort(vet_aux, vet_aux+tam, greater<int>());

        for (int i = 0; i < tam; i++)
        {
            //DBG(vet_aux[i]);
            //DBG(vet[i]);
            if (vet[i] == vet_aux[i])
            {
                resp++;
            }
            
        }
        cout << resp << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome