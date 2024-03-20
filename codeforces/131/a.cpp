#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // A = 65 Z = 90 a = 97 z = 122
    string s;
    cin >> s;
    int a = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] > 90){
            a = 1;
            break;
        }
    }

    if (a == 0) {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] <= 90) {
                s[i] = s[i] + 32;
            }
        }
        if (s[0] > 90) {
            s[0] = s[0] - 32;
        } else {
            s[0] = s[0] + 32;
        }
    }
    
    cout << s << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome