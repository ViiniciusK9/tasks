#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 5123

int s_n, s_m;
string n, m;
int memo[MAX][MAX];


int solve() 
{

    for (int i = 0; i <= s_m; i++)
    {
        memo[0][i] = i;
    }

    for (int i = 0; i <= s_n; i++)
    {
        memo[i][0] = i;
    }
    


    for (int i = 1; i <= s_n; i++)
    {
        for (int j = 1; j <= s_m; j++)
        {
            if (n[i-1] == m[j-1])
            {
                memo[i][j] = memo[i-1][j-1];
            }
            else 
            {
                memo[i][j] = 1 +  min({memo[i-1][j], memo[i-1][j-1], memo[i][j-1]});
            }
        }
    }

    return memo[s_n][s_m];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    s_n = n.size();
    s_m = m.size();

    cout << solve() << '\n';


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome