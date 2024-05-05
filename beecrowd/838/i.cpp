#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(1e5 + 3);

int mat[41][MAX];
array<map<int, int>, 41> ma;



int n, m, c;

bool valid(map<int, int> ar)
{
    int f = -1;
    for (auto el : ar)
    {
        if (f == -1)
        {
            f = el.second;
        }
        else if (f != el.second)
        {
            return false;
        }
    }
    return true;
}

int memo[50];

int solve(int i, map<int, int> ar, int qnt)
{
    if (i == n+1)
    {
        if (valid(ar)) {
            return qnt;
        } else {
            return 0;
        }
    }

    int ans = 0;
    ans = solve(i + 1, ar, qnt);

    for (auto e : ma[i])
    {
        ar[e.first] = ar[e.first] + e.second;
    }
    ans = max(ans, solve(i + 1, ar, qnt + 1));
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            ma[i][mat[i][j]]++;
        }
    }

    cout << solve(1, {}, 0) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome