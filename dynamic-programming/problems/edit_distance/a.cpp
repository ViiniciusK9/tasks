#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 100;

string s1, s2;
int n1, n2;
int memo[MAX][MAX];

int solve(int i, int j)
{
    if (i == n1) {
        return abs(j - n2);
    }

    if (j == n2) {
        return abs(i - n1);
    }

    if (memo[i][j] != 0) return memo[i][j];

    if (s1[i] == s2[j]) {
        memo[i][j] = solve(i+1, j+1);
        return memo[i][j];
    }

    memo[i][j] = 1 + min({solve(i+1, j), solve(i+1, j+1), solve(i, j+1)});
    return memo[i][j];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    cin >> s1 >> s2;
    n1 = s1.size();
    n2 = s2.size();

    
    cout << solve(0, 0) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome