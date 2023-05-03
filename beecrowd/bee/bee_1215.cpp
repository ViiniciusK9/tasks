#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

string s, t;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ult, letra;
    set<string> _set;
    while (getline(cin, s))
    {
        //cout << s << '\n';
        ult = 0;
        letra = 0;
        int i;
        for (i = 0; i < s.length(); i++)
        {
            if (!(i == s.length() -1) && (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                letra = 1;
            } else if (!(i == s.length() -1) && letra && ult != i)
            {
                t = s.substr(ult, abs(ult - i));
                //cout << t << '\n';
                ult = i+1;
                letra = 0;
                for (int i = 0; i < t.length(); i++)
                {
                    t[i] = tolower(t[i]);
                }
                
                _set.insert(t);
            } else if (i == (s.length() -1) && letra) {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                {
                    t = s.substr(ult, abs(ult - i)+1);
                    for (int i = 0; i < t.length(); i++)
                    {
                        t[i] = tolower(t[i]);
                    }
                    
                    _set.insert(t);
                } else {
                    t = s.substr(ult, abs(ult - i));
                    for (int i = 0; i < t.length(); i++)
                    {
                        t[i] = tolower(t[i]);
                    }
                    
                    _set.insert(t);
                }
            }
             else {
                ult = i+1;
                letra = 0;
            }
            
        }

        
        
    }
    
    for (auto &j : _set)
    {
        cout << j << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome