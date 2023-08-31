#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define INF 112345678
#define MAX 1123456

const int M = 1000000007;

typedef long long ll;

int coins[112];
int memo[MAX];
int count[MAX];

int solve(int n)
{
    count[0] = 1;

    for (int x = 1; x <= n; x++)
    {
        for (auto c : coins)
        {
            if (x-c >= 0)
            {
                count[x] += count[x-c];
            }
        }
    }
    

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    for (int i = 0; i < x; i++)
    {
        cin >> coins[i];
    }

    sort(coins, coins + x);

    cout << solve(n) << '\n';

    for (int i = 0; i < n; i++)
    {
        cout << count[i] << " "; 
    }
    

    
    return 0;

}

// g++ -O2 -Wall nome.cpp -o nome