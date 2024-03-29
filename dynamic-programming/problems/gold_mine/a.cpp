#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 100; // adjust the maximum size for your problem

int n, m;

array<array<int, MAX>, MAX> mine;
array<array<int, MAX>, MAX> memoization;
array<array<int, MAX>, MAX> tabulation;

array<int, MAX> dp;
array<int, MAX> prev_dp;



int top_down(int i, int j)
{
    /*
        WARNING WITH THE TESTCASES N==1 E M==1
        ONLY BOTTOM UP WITH MEMORY OPTIMIZATION HAS THIS IMPLEMENTATION
    */

    int ans = 0;
    if (i == -1 && j == -1) {

        for (int k = 0; k < m; k++)
        {
            ans = max(ans, top_down(0, k));
        }
        return ans;
    }

    if (i == n || j < 0 || j == m) {
        return 0;
    }
    return max({mine[i][j] + top_down(i+1, j-1), mine[i][j] + top_down(i+1, j), mine[i][j] + top_down(i+1, j+1)});
}

int top_down_memoization(int i, int j)
{

    /*
        WARNING WITH THE TESTCASES N==1 E M==1
        ONLY BOTTOM UP WITH MEMORY OPTIMIZATION HAS THIS IMPLEMENTATION
    */

    int ans = 0;
    if (i == -1 && j == -1) {

        for (int k = 0; k < m; k++)
        {
            memoization[i][j] = max(ans, top_down_memoization(0, k));
            ans = max(ans, memoization[i][j]);
        }
        return ans;
    }

    if (i == n || j < 0 || j == m) {
        return 0;
    }

    if (memoization[i][j] != 0) return memoization[i][j];

    memoization[i][j] = max({mine[i][j] + top_down_memoization(i+1, j-1), mine[i][j] + top_down_memoization(i+1, j), mine[i][j] + top_down_memoization(i+1, j+1)});

    return memoization[i][j];
}

int bottom_up()
{
    /*
        WARNING WITH THE TESTCASES N==1 E M==1
        ONLY BOTTOM UP WITH MEMORY OPTIMIZATION HAS THIS IMPLEMENTATION
    */

    for (int i = 0; i < m; i++)
    {
        tabulation[n-1][i] = mine[n-1][i];
    }
    
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0) {
                tabulation[i][j] = max(tabulation[i+1][j], tabulation[i+1][j+1]);
            } else if (j == (m-1)) {
                tabulation[i][j] = max(tabulation[i+1][j], tabulation[i+1][j-1]);
            } else {
                tabulation[i][j] = max({tabulation[i+1][j], tabulation[i+1][j-1], tabulation[i+1][j+1]});
            }
            tabulation[i][j] += mine[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, tabulation[0][i]);
    }
    return ans;
}

int bottom_up_memory_optimization()
{
    int ans = 0;

    if (n == 1) {
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, mine[0][i]);
        }
        return ans;
    }

    if (m == 1) {
        for (int i = 0; i < m; i++)
        {
            ans += mine[i][0];
        }
        return ans;
    }

    for (int i = 0; i < m; i++)
    {
        prev_dp[i] = mine[n-1][i];
    }

    for (int i = 0; i < m; i++)
    {
        cout << prev_dp[i] << " ";
    }
    cout << "\n";
    
    
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0) {
                dp[j] = max(prev_dp[j], prev_dp[j+1]);
            } else if (j == (m-1)) {
                dp[j] = max(prev_dp[j], prev_dp[j-1]);
            } else {
                dp[j] = max({prev_dp[j], prev_dp[j-1], prev_dp[j+1]});
            }
            dp[j] += mine[i][j];
        }
        prev_dp = dp;
        for (int i = 0; i < m; i++)
        {
            cout << prev_dp[i] << " ";
        }
        cout << "\n";
    }

    
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, prev_dp[i]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    /*
        WARNING WITH THE TESTCASES N==1 E M==1
        ONLY BOTTOM UP WITH MEMORY OPTIMIZATION HAS THIS IMPLEMENTATION
    */

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mine[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mine[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < MAX; i++)
    {
        fill(memoization[i].begin(), memoization[i].end(), 0);
        fill(tabulation[i].begin(), tabulation[i].end(), 0);
    }

    fill(dp.begin(), dp.end(), 0);
    fill(prev_dp.begin(), prev_dp.end(), 0);
    

    cout << "Top down: " << top_down(-1, -1) << '\n';

    cout << "Top down with mememoization: " << top_down_memoization(-1, -1) << '\n';


    cout << "\nmatriz memoization: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << memoization[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "Top down with tabulation: " << bottom_up() << '\n';

    cout << "\nmatriz tabulation: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << tabulation[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int ans = bottom_up_memory_optimization() ;

    cout << "Top down with memory optimization: " << ans << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome