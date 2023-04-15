#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int flag;
    string s;
    while (cin >> s)
    {
        stack<char> p;
        flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                p.push(s[i]);
            } else if (s[i] == ')') {
                if (p.empty())
                {
                    cout << "incorrect\n";
                    
                    flag = 1;
                    break;
                }
                
                char aux = p.top();
                
                if (aux != '(' ) {
                    cout << "incorrect\n";
                    
                    flag = 1;
                    break;
                }
                
                p.pop();
            }
            
        }
        if (!flag)
        {
            if (!p.empty())
            {
                cout << "incorrect\n";
            } else {

                cout << "correct\n";
            }
            
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome