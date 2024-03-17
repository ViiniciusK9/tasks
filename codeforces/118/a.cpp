#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, aux;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'O' || s[i] == 'o' || s[i] == 'Y' || s[i] == 'y' || s[i] == 'E' || s[i] == 'e' || s[i] == 'U' || s[i] == 'u' || s[i] == 'I' || s[i] == 'i') {
            continue;
        }
        aux.push_back('.');
        aux.push_back(tolower(s[i]));
    }

    cout << aux << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome