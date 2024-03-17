#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, a;
    cin >> s;
    int ans = 0, aux = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'h' && aux == 0) {
            aux++;
        } else if (s[i] == 'e' && aux == 1) {
            aux++;
        } else if (s[i] == 'l' && aux == 2) {
            aux++;
        } else if (s[i] == 'l' && aux == 3) {
            aux++;
        } else if (s[i] == 'o' && aux == 4) {
            ans = 1;
            break;
        }
    }
    
    if (ans == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome