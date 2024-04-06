#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 1123456;

array<int, MAX> memo;

int solve(int n) {
    if (n == 0) return 1;
    if (n < 0) return -1;

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = max(solve(n-2021), solve(n-2020));
    return memo[n];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(memo.begin(), memo.end(), 0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        if (n < 2020) {
            cout << "NO\n";
        } else if (n % 2021 == 0 || n % 2020 == 0) {
            cout << "YES\n";
        } else {
            if (solve(n) == 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            //cout << solve(n) << '\n';
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome