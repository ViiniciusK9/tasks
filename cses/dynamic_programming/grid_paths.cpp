#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1234
#define M 1000000007

int n;

vector<string> sq;
long long int memo[MAX][MAX];

long long int solve(int i, int j)
{
    if (i == n || j == n)
    {
        return 0;
    }

    if (sq[i][j] == '*')
    {
        return 0;
    }

    if (i == n-1 && j == n-1)
    {
        return 1;
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    

    long long int ans = 0;

    ans += (solve(i+1, j) + solve(i, j+1)) % M;
    
    return memo[i][j] = ans;

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sq.push_back(s);
    }
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome