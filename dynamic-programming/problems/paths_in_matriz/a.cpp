#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

array<array<int, 10>, 10> matriz;
array<array<int, 10>, 10> memoization;
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
        memoization[i][j] += top_down(i, j+1);
        return memoization[i][j];
    }

    if (j == m-1) {
        memoization[i][j] += top_down(i + 1, j);
        return memoization[i][j];
    }

    memoization[i][j] += top_down(i + 1, j) + top_down(i, j+1);
    return memoization[i][j];
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

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome