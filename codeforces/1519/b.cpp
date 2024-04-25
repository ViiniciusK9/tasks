#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 101;
int m, n, k;
int memo[MAX][MAX];

int solve(int i, int j, int q) {
    if (i == n && j == m && q == 0) {
        return 1;
    }
    if (i > n || j > m || q < 0){
        return -1;
    }
    if (memo[i][j] != 0) return memo[i][j];
    //DBG(i);
    //DBG(j);
    //DBG(q);

    return memo[i][j] = max(solve(i+1, j, q-j), solve(i, j + 1, q-i));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        memset(memo, 0, sizeof(memo));
        cin >> n >> m >> k;
        if (solve(1, 1, k) == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome