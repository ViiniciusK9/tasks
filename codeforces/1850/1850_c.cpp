#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i, j;
    string s[8];
    cin >> t;
    while (t--)
    {
        for (i = 0; i < 8; i++)
        {
            cin >> s[i];
        }

        int flag = 0;
        
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (s[i][j] != '.')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        while (i < 8 && s[i][j] != '.')
        {
            cout << s[i][j];
            i++;
        }
        cout << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome