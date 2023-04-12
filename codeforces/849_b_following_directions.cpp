#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x, y;
    string s;
    cin >> t;

    while (t--)
    {
        x = y = 0;
        int flag = 1;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
            case 'R':
                x += 1;
                break;
            case 'L':
                x -= 1;
                break;
            default: 
                break;
            }
            if (x == 1 && y == 1)
            {
                cout << "YES\n";
                flag = 0;
                break;
            }
            
        }
        if (flag)
        {
            cout << "NO\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome