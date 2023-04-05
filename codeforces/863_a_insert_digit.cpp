#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, d;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        cin >> s;
        int flag = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] - 48 < d and flag)
            {
                cout << d << s[i];
                flag = 0;
            }
            else
            {
                cout << s[i];
            }
        
            
        }
        if (flag)
        {
            cout << d;
        }
        
        cout << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome