#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b;
    cin >> t;
    string s;

    while (t--)
    {
        cin >> s;
        a = b = 0;
        for (int i = 0; i < 5; i++)
        {
            if (s[i] == 'A') {
                a++;
            }  else {
                b++;
            }
        }
        if (a > b) {
            cout << "A\n";
        } else {
            cout << "B\n";
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome