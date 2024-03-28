#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int n;
array<int, 10> arr;
array<int, 10> memoization;
array<int, 10> tabulation;

int before_prev_dp, prev_dp, dp;


int top_down(int i) {
    if (i >= n) {
        return 0;
    }

    return max(arr[i] + top_down(i+2), top_down(i+1));
}

int top_down_memoization(int i) {
    if (i >= n) {
        return 0;
    }

    if (memoization[i] != 0) {
        return memoization[i];
    }

    memoization[i] = max(arr[i] + top_down_memoization(i+2), top_down_memoization(i+1)); 
    return memoization[i];
}

int bottom_up_tabulation(int jj) {

    if (n == 1) return arr[0];

    tabulation[0] = arr[0];
    tabulation[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        tabulation[i] = max(arr[i] + tabulation[i-2], tabulation[i-1]);
    }

    return tabulation[jj];
}

int bottom_up_memory_optimization() {

    if (n == 1) return arr[0];

    before_prev_dp = arr[0];
    prev_dp = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp = max(before_prev_dp + arr[i], prev_dp);
        before_prev_dp = prev_dp;
        prev_dp = dp;
    }
    
    return prev_dp;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << '\n';

    cout << top_down(0) << '\n';
    
    fill(memoization.begin(), memoization.end(), 0);
    fill(tabulation.begin(), tabulation.end(), 0);

    cout << top_down_memoization(0) << '\n';
    
    cout << bottom_up_tabulation(n-1) << '\n';
    
    // daria para ir coletando informações da entrada sem a necessidade de armazenar os dados no array arr
    cout << bottom_up_memory_optimization() << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome