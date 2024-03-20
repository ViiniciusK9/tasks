#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a1, a2, a3, a4;
    string s;
    cin >> a1 >> a2 >> a3 >> a4;
    cin >> s;
    int ans = 0;

    for(int i = 0; i < s.length(); i++){
        if (s[i] == '1') ans += a1;
        if (s[i] == '4') ans += a4;
        if (s[i] == '2') ans += a2;
        if (s[i] == '3') ans += a3;
    }
    cout << ans << '\n';


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome