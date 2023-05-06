#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans;
    string s, c("codeforces");
    cin >> n;

    while (n--)
    {
        ans = 10;
        cin >> s;
        
        for (int i = 0; i < 10; i++)
        {
            if (s[i] == c[i])
            {
                ans--;
            }
        }
        
        cout << ans << "\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome