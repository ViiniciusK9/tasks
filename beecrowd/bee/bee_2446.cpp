#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAXM = (int) 10e3+1;
const int MAXV = (int) 10e5+1;

int v, m;
int vet[MAXM];
int memo[MAXV];


int dp(int l, int index)
{
    int ans = 0;

    if (index == m)
    {
        return 0;
    }

    if (l < 0)
    {
        return 0;
    }

    if (l == 0)
    {
        return 1;
    }

    if (memo[l] != -1)
    {
        return memo[l];
    }

    ans = max(dp(l - vet[index], index+1), dp(l, index+1));

    return memo[l] = ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> vet[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << (dp(v, 0) == 1 ? "S" : "N") << '\n';

    /*
    for (int i = 0; i < m; i++)
    {
        cout << memo[i] << ' ';
    }
    */

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome