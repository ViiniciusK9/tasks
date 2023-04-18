#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n, o, v;
    int maior = 0;
    set<string> nomes;
    set<string> nomes_n;
    while (cin >> n)
    {
        if (n == "FIM")
        {
            break;
        }
        cin >> o;
        if (o == "YES"){
            nomes.insert(n);
            if (n.length() > maior) {
                v = n;
                maior = n.length();
            }
        } else {
            nomes_n.insert(n);
        }
    }
    
    for (auto &j : nomes)
    {
        cout << j << '\n';
    }

    for (auto &j : nomes_n)
    {
        cout << j << '\n';
    }

    cout << '\n';
    cout << "Amigo do Habay:\n";
    cout << v << '\n';

    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome