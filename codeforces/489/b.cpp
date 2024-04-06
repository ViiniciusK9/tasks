#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 112;

vector<int> b;
vector<int> g;
int n, m, aux;

array<array<int, MAX>, MAX> memo;

int solve(int i, int j)
{
    if (i == n || j == m) return 0;

    if (memo[i][j] != 0) return memo[i][j];

    if (abs(b[i] - g[j]) <= 1) 
    {
        memo[i][j] = 1 + solve(i+1, j+1);
        return memo[i][j];
    }

    if (b[i] > g[j]) {
        memo[i][j] = solve(i, j+1);
        return memo[i][j];
    }

    memo[i][j] = solve(i+1, j);
    return memo[i][j];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    for (int i = 0; i < MAX; i++)
    {
        fill(memo[i].begin(), memo[i].end(), 0);
    }
    
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        b.push_back(aux);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        g.push_back(aux);
    }
    
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    cout << solve(0, 0) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome