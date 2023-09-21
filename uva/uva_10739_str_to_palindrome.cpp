#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;
string s;

int memo[1123][1123];

int dp(int i, int j)
{
    int ans = 0;
    DBG(i);
    DBG(j);
    while (i >= 0 && j < s.size())
    {
        if (s[i] == s[j]) 
        {
            ans++;
        }
        i--;
        j++;
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 1, i, j, ans;
    cin >> t;
    while (t--)
    {
        
        cin >> s;
        memset(memo, -1, sizeof(memo));
        if (s.size() % 2 != 1)
        {
            ans = (s.size() / 2);
            i = (s.size() / 2) - 1;
            j = (s.size() / 2) + 1;
        }
        else
        {
            ans = (s.size() / 2);
            i = (s.size() / 2) - 1;
            j = (s.size() / 2);
        }
        ans -= dp(i, j);
        cout << "Case " << c << ": " << ans  << "\n";
        c++;
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome