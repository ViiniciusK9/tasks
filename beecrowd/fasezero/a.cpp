#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    string s;
    cin >> s;
    int c = 0;
    int x = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'O')
        {
            c++;
        }
    }
    if (c >= 2 || c == 0)
    {
        cout << "?\n";
    } else if (s[0] == s[1] || s[1] == s[2]) {
        cout << "Alice\n";
    } else {
        cout << "*\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome