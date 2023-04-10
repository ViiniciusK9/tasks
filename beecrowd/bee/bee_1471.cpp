#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vet[11234];
    memset(vet, 0, sizeof(vet));

    int n, r, i, aux = 1, flag;
    while (cin >> n)
    {
        cin >> r;
        for (int j = 0; j < r; j++)
        {
            cin >> i;
            vet[i] = aux;            
        }
        flag = 1;
        for (int j = 1; j < n+1; j++)
        {
            if (vet[j] != aux)
            {
                if (flag)
                {
                    flag = 0;
                } 
                cout << j << " ";
            }
        }
        if (flag)
        {
            cout << "*\n";
        } else {
            cout << "\n";
        }
        

        

        aux++;
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome