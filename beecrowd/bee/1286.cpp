#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

vector<pair<int, int>> vet;
int memo[100][100];
int solve(int n, int i)
{
    if (n < 0) {
        return -10000;
    }

    if (n == 0) {
        return 0;
    }

    if (i == vet.size()) {
        return 0;
    }
    
    if (memo[n][i] != 0) return memo[n][i];

    memo[n][i] = max(solve(n - vet[i].second, i+1) + vet[i].first, solve(n, i+1));
    return memo[n][i];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p, t, q;
    while (cin >> n)
    {
        vet.clear();
        if (n == 0){
            break;
        }
        memset(memo, 0, sizeof(memo));
        cin >> p;
        for (int i = 0; i < n; i++)
        {
            cin >> t >> q;
            vet.push_back({t, q});
        }

        cout << solve(p, 0) << " min." << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome