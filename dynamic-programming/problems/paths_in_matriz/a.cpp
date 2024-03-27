#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

array<array<int, 10>, 10> matriz;
array<array<int, 10>, 10> memoization;
array<array<int, 10>, 10> tabulation;

array<int, 10> previous;
array<int, 10> dp;

int n, m;


int top_down(int i, int j) {
    int ans = 0;

    if (i == n-1 && j == m-1){
        return 1;
    }

    if (matriz[i][j] == 1) return 0;

    if (i == n-1) {
        ans += top_down(i, j+1);
        return ans;
    }

    if (j == m-1) {
        ans += top_down(i + 1, j);
        return ans;
    }

    ans += top_down(i + 1, j);
    ans += top_down(i, j+1);
    return ans;
}

int top_down_memoization(int i, int j) {
    if (i == n-1 && j == m-1){
        return 1;
    }

    if (matriz[i][j] == 1) return 0;

    if (memoization[i][j] != 0) return memoization[i][j];

    if (i == n-1) {
        memoization[i][j] = top_down_memoization(i, j+1);
        return memoization[i][j];
    }

    if (j == m-1) {
        memoization[i][j] = top_down_memoization(i + 1, j);
        return memoization[i][j];
    }

    memoization[i][j] = top_down_memoization(i + 1, j) + top_down_memoization(i, j+1);
    return memoization[i][j];
}

int bottom_up(int ii, int jj) {

    tabulation[0][0] = 1;

    for (int i = 1; i < m; i++)
    {
        tabulation[0][i] = (matriz[0][i] == 0) ? tabulation[0][i-1] : 0;
    }

    for (int i = 1; i < n; i++)
    {
        tabulation[i][0] = (matriz[i][0] == 0) ? tabulation[i-1][0] : 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            tabulation[i][j] = (matriz[i][j] == 0) ? (tabulation[i][j-1] + tabulation[i-1][j]) : 0;
        }
    }

    return tabulation[ii][jj];
}

int bottom_up_memory_optimization(int ii, int jj){

    previous[0] = 1;

    for (int i = 1; i < m; i++)
    {
        previous[i] = (matriz[0][i] == 0) ? previous[i-1] : 0;
    }

    for (int i = 0; i < m; i++)
    {
        cout << previous[i] << " ";
    }
    cout << '\n';

    for (int i = 1; i < n; i++)
    {
        dp[0] = (matriz[i][0] == 0) ? previous[0] : 0;
        for (int j = 1; j < m; j++)
        {
            dp[j] = (matriz[i][j] == 0) ? (dp[j-1] + previous[j]) : 0;
        }
        previous = dp;
        for (int i = 0; i < m; i++)
        {
            cout << previous[i] << " ";
        }
        cout << '\n';
    }

    return previous[jj];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    // n = linha
    // m = coluna
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cin >> matriz[i][k];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matriz[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << top_down(0, 0) << '\n';

    for (int i = 0; i < 10; i++)
    {
        fill(memoization[i].begin(), memoization[i].end(), 0);
        fill(tabulation[i].begin(), tabulation[i].end(), 0);
    }

    cout << top_down_memoization(0, 0) << '\n';
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << memoization[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << bottom_up(n-1, m-1) << '\n';
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << tabulation[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "\n\n\n";

    int ans = bottom_up_memory_optimization(n-1, m-1);
    
    cout << ans << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome