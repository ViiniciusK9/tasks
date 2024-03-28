#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

string s1, s2;
array<array<int, 100>, 100> memoization;

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


// esta errado
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

int bottom_up(int i1, int i2)
{
    
    
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> s1 >> s2;

    fill(memoization.begin(), memoization.end(), 0);

    cout << top_down(0, 0) << '\n';

    cout << top_down_memoization(0, 0) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome