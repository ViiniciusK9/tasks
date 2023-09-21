#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    string s;
    char ant = 'x';
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (ant != s[i]) 
        {
            ant = s[i];
            ans++;
        } 
    }
    

    cout << min(n, ans + 2) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome