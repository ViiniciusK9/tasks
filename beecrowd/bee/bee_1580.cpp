#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1234
#define P 1000000007

typedef long long ll;

ll exp_bin(ll a, ll e){
    // algoritmo de exponenciação binaria utilizando mod P 10e9+7 para não ser muito grande e respeitar o problema
    // caso queira só o algoritmo de exponenciação binaria só retirar o () % P
    if (e == 0)
    {
        return 1;
    }

    if (e & 1)
    {
        return (a * exp_bin(a, e - 1)) % P;
    }
    ll b = exp_bin(a, e / 2);
    return (b * b) % P;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll fact[MAX], a, b;
    char n[MAX];
    int freq[26], i, tam;

    // inicializar o vetor fact com seus respectivos resultados já efetuando () % 10e9+7 
    fact[0] = 1;
    for (i = 1; i < MAX; i++) {
        fact[i] = (fact[i-1] * i) % P;
    }

    while ((cin >> n))
    {
        tam = strlen(n);                        // tamanho da string n
        memset(freq, 0, sizeof(freq));          // para setar o vetor freq com 0
        for (i = 0; i < tam; i++)
        {
            freq[n[i] - 'A']++;                 // armazenando a frequancia de cada letra da string n no vetor freq
        }
        a = fact[tam];
        b = 1;
        for (i = 0; i < 26; i++)
        {
            b = (b * fact[freq[i]]) % P;
        }
        cout << (a * exp_bin(b, P-2)) % P << '\n';
    }
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome