#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)



int memo[2][212345];

bool solve (int i, int j) {
    if (i == 2 && j == n) {
        memo[i][j] =1;
        return true;
    }

    if (memo[i][j] != 0) {
        return memo[i][j];
    }

    if (i == 0) {
        if (m[{i+1, j}] == '>') {
            solve(i+1, j+1);
        } else {
            solve(i+1, j-1);
        }
    } else {
        if (m[{i-1, j}] == '>') {
            solve(i-1, j+1);
        } else {
            solve(i-1, j-1);
        }
    }

    if (j + 1 < n-1) {
        if (m[{i, j+1}] == '>'){
            solve(i, j+2);
        }
    }
    
    if ()


}
map<pair<int, int>, char> m;
int t, n;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    char aux;
    cin >> t;
    

    while (t--)
    {
        m.clear();
        memset(memo, 0, sizeof(memo));
        cin >> n;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> aux;
                m[{i, j}] = aux; 
            }
        }

        solve(0, 0);
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome