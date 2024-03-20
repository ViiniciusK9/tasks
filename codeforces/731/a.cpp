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
    int ans = 0;

    char ant = 'a';

    for(int i = 0; i < s.length(); i++){
        DBG(min(abs(ant - s[i]), 26 - abs(ant - s[i])));
    }
    cout << ans << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome