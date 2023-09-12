#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int vet[26];
    char aux;
    memset(vet, 0, sizeof(vet));
    string a("codeforces");
    for (int i = 0; i < a.length(); i++)
    {
        vet[a[i] - 'a'] = 1;
    }
    
    cin >> t;

    while (t--)
    {
        cin >> aux; 
        if (vet[aux - 'a'])
        {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome