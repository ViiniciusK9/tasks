#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c;
    int vet[26], ans = 0;

    memset(vet, 0, sizeof(vet));

    while ((c = getchar()) != EOF)
    {
        if (c >= 97 and c <= 122)
        {
            vet[c-97]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (vet[i] != 0) {
            ans++;
        }
    }
    cout << ans << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome