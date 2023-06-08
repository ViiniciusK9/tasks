#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(6)<<(x)

long long int n, k, l;

long long int dp(long long i) {
    long long int ans = 0;

    for (int j = 0; j <= n; j+=10)
    {
        if (j + 5 <= n)
        {
            ans += (k * 2);
        }
        if (j + 10 <= n)
        {
            ans += l;
        }
        
    }
    
    
    return ans;
}



int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    while (cin >> n >> k >> l && n != EOF)
    {
        
        printf("%06d\n",  (dp(0) % 1000000));
        //cout << dp(0) % 1000000 << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome