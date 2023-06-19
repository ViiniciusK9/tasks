#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


int n, t;
vector<pair<int, int>> vet;
int memo[111][611];

int dp(int i, int w) {
    int ans = 0;
    if (w <= 0 || i == n)
    {
        return 0;
    }
    if (memo[i][w] != -1)
    {
        return memo[i][w];
    }

    ans = max(((w - vet[i].first) < 0 ? (dp(i+1, w)) : (dp(i, w-vet[i].first) + vet[i].second)), dp(i+1, w));
    
    return memo[i][w] = ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a1, a2, ins = 1;

    while (cin >> n >> t && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a1 >> a2;
            vet.push_back({a1, a2});
        }
        memset(memo, -1, sizeof(memo));
        cout << "Instancia " << ins++ << '\n';
        cout << dp(0, t) << "\n\n";   

        vet.clear();     
    }
        
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome