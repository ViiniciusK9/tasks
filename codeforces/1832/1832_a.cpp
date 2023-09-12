#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        if (s.length() == 2)
        {
            cout << "NO\n";
        } else {
            map<char, int> m;
            for (int i = 0; i < s.length(); i++)
            {
                m[s[i]]++;
            }
            if (m.size() == 1)
            {
                cout << "NO\n";
            } else if (m.size() == 2) {
                int at = 1;
                for (auto &j : m)
                {
                    if (j.second < 2)
                    {
                        at = 0;
                    }
                }
                if (at)
                {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "YES\n";
            }
            
        }
        
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome