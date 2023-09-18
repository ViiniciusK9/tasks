#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int vet[60];
int memo[1010][1010];

int dp(int l, int r)
{
    if (r - l == 1) return 0;
    if (memo[l][r] != -1) return memo[l][r];

    int ans = INT_MAX;
    for (int i = l+1; i < r; i++)
    {
        ans = min(ans, vet[r]-vet[l] + dp(l, i) + dp(i, r));
    }
    return memo[l][r] = (ans == INT_MAX ? 0 : ans);
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, n;
    
    while (cin >> l && l != 0)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];   
        }
        vet[n] = 0;
        vet[n+1] = l;
        sort(vet, vet+n+2);
        memset(memo, -1, sizeof(memo));
        cout << "The minimum cutting is " << dp (0, n+1) << ".\n";
        
    }
    


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome