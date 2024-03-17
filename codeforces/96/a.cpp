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

    int i0 = 0, i1 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1') {
            i1++;
            i0 = 0;
        } else {
            i0++;
            i1 = 0;
        }
        if (i1 == 7 || i0 == 7) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome