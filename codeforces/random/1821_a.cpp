#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n;
    while (n--)
    {
        int ans = 1;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0' and i == 0)
            {
                ans = -1;
                break;
            }
            
            if (s[i] == '?' and i == 0)
            {
                ans *= 9;
            } else if (s[i] == '?') {
                ans *= 10;
            }
        }

        if (ans > 1) {
            cout << ans << '\n';
        } else if (ans == -1) {
            cout << "0\n";
        } else {
            cout << ans << '\n';
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome