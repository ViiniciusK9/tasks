#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int ch[300], ans = 0;
    memset(ch, 0, sizeof(ch));
    for (int i = 0; i < s.size(); i++)
    {
        if (ch[s[i]] == 0)
        {
            ans++;
            ch[s[i]] = 1;
        }
    }
    cout << (((ans % 2) != 0) ? "IGNORE HIM!\n" : "CHAT WITH HER!\n");

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome