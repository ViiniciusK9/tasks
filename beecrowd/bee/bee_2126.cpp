#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n1;
    string n2;
    int c = 1;
    while (cin >> n1 >> n2)
    {
        int i = 0, qnt = 0, ult = 0;
        while (i < (n2.length()))
        {
            if (i + n1.length() > n2.length())
            {
                break;
            }
            //DBG(n2.substr(i, n1.length()));
            //DBG(n1);
            if (n1 == n2.substr(i, n1.length()))
            {
                qnt++;
                ult = i+1;
            } 
            i++;
        }
        if (qnt == 0) {

            cout << "Caso #" << c << ":\n";
            cout << "Nao existe subsequencia\n";
        } else {
            cout << "Caso #" << c << ":\n";
            cout << "Qtd.Subsequencias: " << qnt << "\n";
            cout << "Pos: " << ult << "\n";
        }
        cout << '\n';
        c++;
    }
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome