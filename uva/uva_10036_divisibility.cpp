#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;
int t, n, k;
int vet[11234];

bool memo[10034][220];

bool dp(int i, int sum)
{
    int ver = (sum < 0) ? abs(sum) + 100 : sum;
    if (i == n) return (sum % k == 0);
    if (memo[i][ver] == true) return memo[i][ver];

    bool ans;
    ans = dp(i+1, (sum + vet[i]) % 100) || dp(i+1, (sum - vet[i]) % 100);

    return memo[i][sum] = ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
        }
        memset(memo, false, sizeof(memo));
        cout << ((dp(1, vet[0]) == true) ? "Divisible" : "Not divisible") << '\n';

    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome