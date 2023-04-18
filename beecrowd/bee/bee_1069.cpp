#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans;
    string s;
    cin >> n;
    while (n--)
    {
        ans = 0;
        stack<char> p;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '<')
            {
                p.push(s[i]);
            } else if (s[i] == '>') {
                if (!p.empty())
                {
                    ans++;
                    p.pop();
                }
                
            }
            
        }
        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome