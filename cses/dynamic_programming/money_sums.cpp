#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 112

set<int> s;
int n;
int coins[MAX];
bool memo[110][11234568];

void solve (int i, int value)
{
    if (memo[i][value] != false) return;
    if (i == n)
    {
        memo[i][value] = true;
        s.insert(value);
        return;
    }

    
    solve(i+1, value);
    solve(i+1, value+coins[i]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    memset(memo, false, sizeof(memo));
    solve(0, 0);
    cout << s.size()-1 << '\n';
    for (auto j : s)
    {
        if (j == 0) continue;

        
        cout << j << " ";
    }

    cout << '\n';

    return 0;
}