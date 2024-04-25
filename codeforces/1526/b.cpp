#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed << std::setprecision(1) << (x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 1e9 + 9;

bool memo[MAX];
vector<int> coin = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};

void solve()
{
    memo[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        memo[i] = 0;
        for (auto c : coin)
        {
            if (i - c >= 0)
            {
                memo[i] = max(memo[i], memo[i - c]);
            }
            else
            {
                break;
            }
            if (memo[i])
                break;
        }
    }
}

bool solve2(int n)
{

    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    if (memo[n] == 1)
        return memo[n];

    for (auto c : coin)
    {
        memo[n] = max(solve2(n - c), memo[n]);
        if (memo[n]) break;
    }
    return memo[n];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;
    //bool a = ;
    while (t--)
    {
        cin >> n;
        if (solve2(n) == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome