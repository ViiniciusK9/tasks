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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(500);

int dp[MAX][MAX];
int mat[MAX][MAX];
array<int, MAX> previ;
array<int, MAX> at;

int n, m;

int square()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = mat[i][0];
        ans = max(ans, dp[i][0]);
    }

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = mat[0][i];
        ans = max(ans, dp[0][i]);
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;
}

int square_memory()
{
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        previ[i] = mat[0][i];
        ans = max(ans, previ[i]);
    }
    
    for (int i = 1; i < n; i++)
    {
        at[0] = mat[i][0];
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] == 0) {
                at[j] = 0;
            } else {
                at[j] = 1 + min({at[j-1], previ[j], previ[j-1]});
            }
            ans = max(ans, at[j]);
        }
        previ = at;
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << pow(square(), 2) << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    
    cout << pow(square_memory(),2) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome