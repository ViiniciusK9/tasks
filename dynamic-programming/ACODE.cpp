#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

string s;
vector<int> memo;


int dp (int i)
{
    if (i == s.size()) return 1;

    if (memo[i] != -1) return memo[i];

    int ans = 0;
    if (s[i] >= '1' && s[i] <= '9')
    {
        ans += dp(i + 1);
    }

    if (i + 1 < s.size() && s[i] == '1')
    {
        ans += dp(i + 2);
    }

    if (i + 1 < s.size() && s[i] == '2' && s[i+1] <= '6')
    {
        ans += dp(i + 2);
    }

    return memo[i] = ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> s;       
        if (s[0] == '0') break;

        memo.clear();
        memo.resize(s.size(), -1);

        cout << dp(0) << '\n';
        
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome