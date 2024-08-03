#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 2e5+10;

int n;
string s1;
int memo[MAX][3];

int ponto(int i, int j) {
    if (s1[i] == 'S' && j == 0) {
        return 1;
    } else if (s1[i] == 'R' && j == 1) {
        return 1;
    } else if (s1[i] == 'P' && j == 2) {
        return 1;
    }

    return 0;
}

// r = 0, p = 1, s = 2

int solve(int i, int u) {
    if (i == n) {
        return 0;
    }

    if (u != -1 && memo[i][u] != -1) {
        return memo[i][u];
    }

    int ans = 0;
    if (u != 0 && s1[i] != 'P') {
        ans = solve(i+1, 0) + ponto(i, 0);
    }

    if (u != 1 && s1[i] != 'S') {
        ans = max(ans, solve(i+1, 1) + ponto(i, 1));
    }

    if (u != 2 && s1[i] != 'R') {
        ans = max(ans, solve(i+1, 2) + ponto(i, 2));
    }

    memo[i][u] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s1;
    memset(memo, -1, sizeof(memo));
    cout << solve(0, -1) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome