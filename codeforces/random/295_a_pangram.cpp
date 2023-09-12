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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto & c: s) c = toupper(c);
    //cout << s << '\n';
    for(int i = 0; i < n; i++) {
        vet[s[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (vet[i] == 0)
        {
            cout << "NO\n";
            return 0;
        }
        
    }
    
    cout << "YES\n";
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome