#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

array<array<int, 10>, 10> matriz;
array<array<int, 10>, 10> memo;
array<array<int, 10>, 10> tabulation;

array<int, 10> previous;
array<int, 10> dp;


int n, m;

int top_down_no_memoization(int i, int j) {
    if (i == m-1 && j == n-1) {
        return matriz[i][j];
    }

    if (i == m-1) {
        return matriz[i][j] + top_down_no_memoization(i, j+1);
    }

    if (j == n-1) {
        return matriz[i][j] + top_down_no_memoization(i+1, j);
    }

    return matriz[i][j] + min(top_down_no_memoization(i+1, j), top_down_no_memoization(i, j +1));
}

int top_down(int i, int j) {

    if (i == m-1 && j == n-1) {
        return matriz[i][j];
    }

    if (memo[i][j] != 0) {
        return memo[i][j];
    }

    if (i == m-1) {
        memo[i][j] = matriz[i][j] + top_down(i, j+1);
        return memo[i][j];
    }

    if (j == n-1) {
        memo[i][j] = matriz[i][j] + top_down(i+1, j);
        return memo[i][j];
    }

    memo[i][j] = matriz[i][j] + min(top_down(i+1, j), top_down(i, j +1));
    return memo[i][j];
}


int bottom_up(int ii, int jj) {
    tabulation[0][0] = matriz[0][0];
    for (int i = 1; i < n; i++)
    {
        tabulation[0][i] = tabulation[0][i-1] + matriz[0][i];
    }

    for (int i = 1; i < m; i++)
    {
        tabulation[i][0] = tabulation[i-1][0] + matriz[i][0];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            tabulation[i][j] = min(tabulation[i-1][j], tabulation[i][j-1]) + matriz[i][j];
        }
    }
    
    return tabulation[ii][jj];
}


int bottom_up_mem_optimization(int jj) {
    previous[0] = matriz[0][0];
    for (int i = 1; i < n; i++)
    {
        previous[i] = previous[i-1] + matriz[0][i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << previous[i] << ' ';
    }
    cout << '\n';
    

    for (int i = 1; i < m; i++)
    {
        dp[0] = previous[0] + matriz[i][0];
        for (int j = 1; j < n; j++)
        {
            dp[j] = min(dp[j-1], previous[j]) + matriz[i][j];
        }

        previous = dp;

        for (int x = 0; x < n; x++)
        {
            cout << previous[x] << ' ';
        }
        cout << '\n';
    }
    
    return previous[jj];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // n = colunas
    // m = linhas
    cin >> n >> m;

    

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
            memo[i][j] = matriz[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';


    cout << "Top-down sem memoization: " << top_down_no_memoization(0, 0) << '\n';

    // Setting the memoization and tabulation matrix to zero
    for (int i = 0; i < 10; i++)
    {
        fill(memo[i].begin(), memo[i].end(), 0);
        fill(tabulation[i].begin(), tabulation[i].end(), 0);
    }

    // Using memoization
    cout << "Top-down com memoization: " << top_down(0, 0) << '\n';
    
    // Print matriz of memoization
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "Bottom-up utilizando tabulação completa: " << bottom_up(m-1, n-1) << '\n';

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tabulation[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    int ans = bottom_up_mem_optimization(n-1);

    cout << "Bottom-up com otimização de memoria: " << ans << '\n';



    /*
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << '\n';
    }
    */



    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome