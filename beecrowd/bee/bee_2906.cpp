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
    set<string> sett;
    while (n--)
    {
        char aux[101];
        int x = 0;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            
            if (s[i] == '@')
            {
                for (int j = i; j < s.length(); j++)
                {
                    aux[x++] = s[j];
                }
                
                break;
            } else if (s[i] == '.') {
                continue;
            } else if (s[i] == '+') {
                for (int j = i; j < s.length(); j++)
                {
                    if (s[j] == '@')
                    {
                        for (int t = j; t < s.length(); t++)
                        {
                            aux[x++] = s[t];
                        }
                        break;
                    } else {
                        continue;
                    }
                }
                break;
            } else {
                aux[x++] = s[i];
            }
            
        }
        aux[x] = '\0';
        //cout << aux << '\n';
        sett.insert(aux);
    }
    cout << sett.size() << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome