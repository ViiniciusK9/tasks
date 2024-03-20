#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string ans;
    string word;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (i+2 < s.length()) {
            if (s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
                if (!empty(word)) {

                    if (!empty(ans))
                    {
                        ans.push_back(' ');
                    }
                    
                    for (int j = 0; j < word.length(); j++)
                    {
                        ans.push_back(word[j]);
                    }
                    
                }
                word.clear();
                i+=2;
                continue;
            }
        }
        word.push_back(s[i]);


    }

    if (!empty(word)) {
        if (!empty(ans))
        {
            ans.push_back(' ');
        }
        
        for (int j = 0; j < word.length(); j++)
        {
            ans.push_back(word[j]);
        }
        
    }
    cout << ans << '\n';


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome