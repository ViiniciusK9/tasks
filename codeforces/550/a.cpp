#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

const int MAX = 1e5 + 3;

int n;
string s;
array<int, MAX> memo;

int solve(int i, int a1, int a2)
{

    if (i == n && a1 == 1 && a2 == 1)
    {
        return 1;
    }

    if (i == n)
    {
        return 0;
    }

    if (a1 == 1 && a2 == 1)
    {
        return 1;
    }

    if (memo[i] != -1)
        return memo[i];

    if (s[i] == 'A' && (i + 1 < n) && s[i + 1] == 'B')
    {
        return memo[i] = max(solve(i + 1, a1, a2), solve(i + 2, a1 + 1, a2));
    }
    else if (s[i] == 'B' && s[i + 1] == 'A')
    {
        return memo[i] = max(solve(i + 1, a1, a2), solve(i + 2, a1, a2 + 1));
    }
    else
    {
        return memo[i] = solve(i + 1, a1, a2);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    n = s.length();

    /*
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A' && (i+2 < n) && s[i+1] == 'B' && s[i+2] == 'A') {
            a1++;
            a2++;
            i+=1;
        } else if (s[i] == 'A' && (i+1 < n) && s[i+1] == 'B') {
            a2++;
        } else if (s[i] == 'B' && (i+1 < n) && s[i+1] == 'A') {
            a3++;
        }

        if ((a1 == 2 || (a2 == 1 && a3 == 1) || (a1 == 1 && a3 == 2 && n>=5) || (a2 == 2 && a1 == 1 && n>=5) )&& n >= 4) {
            cout << "YES\n";
            return 0;
        }
    }
    */
    fill(memo.begin(), memo.end(), -1);
    if (solve(0, 0, 0) == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome