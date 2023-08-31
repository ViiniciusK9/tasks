#include<bits/stdc++.h>
 
using namespace std;
 
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
 
int n, x;
int vet[1123456];
int memo[1123456];
 
long long int dp(int w) {
    long long int ans = 0;
    if (w < 0)
    {
        return 0;
    }
 
    if (w == 0)
    {
        return 1;
    }

    if (memo[w] != -1)
    {
        return memo[w];
    }
 
    for (int i = 0; i < n; i++)
    {
        ans += dp(w - vet[i]);
    }
 
    return memo[w] = (ans % 1000000007);
}
 
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
 
    memset(memo, -1, sizeof(memo));
    
    cout << dp(x) << "\n";
 
    
    return 0;
}
 
// g++ -O2 -Wall nome.cpp -o nome