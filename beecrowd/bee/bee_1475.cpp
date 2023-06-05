#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define INF 1123456;


int n, c, t1, t2;
int vet[1005];

int memo[1123456];

int dp(int i, int w) {
    if (w-1 == vet[n-1])
    {
        return 0;
    }
    if (w-1 >= vet[n-1])
    {
        return 0;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }
    
    int ans;

    ans = min(
        dp(upper_bound(vet, vet+n, vet[i]+ t1) - vet, vet[i] + t1 + 1) + t1,
        dp(upper_bound(vet, vet+n, vet[i]+ t2) - vet, vet[i] + t2 + 1) + t2
    );

    return memo[i] = ans;

}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> c >> t1 >> t2 && n != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
        }
        memset(memo, -1, sizeof(memo));
        cout << dp(0, vet[0]) << '\n';
    
    }
        
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome