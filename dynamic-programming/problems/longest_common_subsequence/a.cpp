#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

string s1, s2;
array<array<int, 100>, 100> memoization;
array<array<int, 100>, 100> tabulation;
array<int, 100> dp;
array<int, 100> prev_dp;

int top_down(int i1, int i2)
{
    if (i1 >= s1.length() || i2 >= s2.length()) {
        return 0;
    }

    if (s1[i1] == s2[i2]) {
        return 1 + top_down(i1 +1, i2 + 1);
    }

    return max(top_down(i1, i2+1), top_down(i1+1, i2));
}



int top_down_memoization(int i1, int i2)
{
    if (i1 >= s1.length() || i2 >= s2.length()) {
        return 0;
    }

    if (s1[i1] == s2[i2]) {
        memoization[i1][i2] = 1 + top_down_memoization(i1 +1, i2 + 1);
        return memoization[i1][i2];
    }

    memoization[i1][i2] = max(top_down_memoization(i1, i2+1), top_down_memoization(i1+1, i2));
    return memoization[i1][i2];
}

int bottom_up()
{
    
    for (int i = 1; i < s1.length() + 1; i++)
    {
        for (int j = 1; j < s2.length() + 1; j++)
        {
            if (s1[i-1] == s2[j-1]) {
                tabulation[i][j] = 1 + tabulation[i-1][j-1];
            } else {
                tabulation[i][j] = max(tabulation[i-1][j], tabulation[i][j-1]);
            }
        }
    }
    return tabulation[s1.length()][s2.length()];
    
}

int bottom_up_memory_optimization()
{
    //dp and prev_dp need have a lenght of m+1 coluns
    for (int i = 1; i < s1.length() + 1; i++)
    {
        for (int j = 1; j < s2.length() + 1; j++)
        {
            if (s1[i-1] == s2[j-1]) {
                dp[j] = 1 + prev_dp[j-1];
            } else {
                dp[j] = max(prev_dp[j], dp[j-1]);
            }
        }
        prev_dp = dp;
        fill(dp.begin(), dp.end(), 0);
    }
    return prev_dp[s2.length()];
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> s1 >> s2;

    for (int i = 0; i < 100; i++)
    {
        fill(memoization[i].begin(), memoization[i].end(), 0);
        fill(tabulation[i].begin(), tabulation[i].end(), 0);
    }
    fill(dp.begin(), dp.end(), 0);
    fill(prev_dp.begin(), prev_dp.end(), 0);

    cout << top_down(0, 0) << '\n';

    cout << top_down_memoization(0, 0) << '\n';

    cout << "Bottom-up: " << bottom_up() << '\n';
    
    for (int i = 0; i < s1.length() + 1; i++)
    {
        for (int j = 0; j < s2.length() + 1; j++)
        {
            cout << tabulation[i][j] << ' ';
        }
        cout << '\n';
    }
    
    cout << "\nBottom-up memory optimization: " << bottom_up_memory_optimization() << '\n';
    
    /*
        Existe um algoritmo chamado Hunt-Szymanski algorithm
        que tambem soluciona este problema, mas utiliza outra
        abordagem (verificar caso sejá interessante fazer o problema
        em O(n log n))
    */

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome