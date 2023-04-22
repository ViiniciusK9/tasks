#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vet[26];
    memset(vet, 0, sizeof(vet));
    string s;
    int n;
    
    cin >> s;
    n = s.length();

    for (int i = 0; i < n; i++)
    {
        vet[s[i] -'A']++;
    }

    int quant = 0;

    for (int i = 0; i < 26; i++)
    {
        if ((vet[i] % 2) != 0)
        {
            quant++;
        }
    }

    if ((n % 2) == 0 and quant > 1 or (n % 2) != 0 and quant >= 2)
    {
        cout << "NO SOLUTION\n";
    } else {
        char aux, at;
        for (int i = 0; i < 26; i++)
        {
            
            if (vet[i] % 2 != 0)
            {
                aux = i + 'A';
                quant = vet[i] / 2;
                vet[i] -= quant + 1;
                at = i + 'A';
                for (int j = 0; j < quant; j++)
                {
                    cout << at;
                }
            } else {
                quant = vet[i] / 2;
                vet[i] -= quant;
                at = i + 'A';
                for (int j = 0; j < quant; j++)
                {
                    cout << at;
                }
                
            }
            
        }
        if ((n % 2) != 0)
        {
            cout << aux;
        }
        
        for (int i = 25; i >= 0; i--)
        {
            quant = vet[i];
            vet[i] -= quant;
            at = i + 'A';
            for (int j = 0; j < quant; j++)
            {
                cout << at;
            }
        }
    }
    
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome