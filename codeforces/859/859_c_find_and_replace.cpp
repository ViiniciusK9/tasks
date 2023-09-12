#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, flag = 0;
    string s;
    char aux, ac;

    cin >> t;
    while (t--)
    {
        flag = 0;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            aux = s[i];
            if (!(aux >= 'a' and aux <= 'z'))
            {
                continue;
            }
            
            if ((i % 2) == 0)
            {
                ac = '0';
            } else {
                ac = '1';
            }
            
            for (int j = i; j < n; j++)
            {
                if (aux == s[j])
                {
                    s[j] = ac;
                } 
            }
        }
        for (int i = 0; i < n; i++)
        {
            if ((i % 2 == 0) and s[i] == '1' or (i % 2 != 0) and s[i] == '0')
            {
                flag = 1;
                break;
            }
        }
        
        if (flag)
        {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
            
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome