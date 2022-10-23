#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define INF 1000000000

const int MAXV = (int)10e5+1;
const int MAXM = (int)10e3+1;

int memo[MAXM][MAXV];
int saldo[MAXM];

int v, m;

int solve(int idx, int val){

    if (val < 0)
    {   
        return INF;
    }

    if (idx == m && val > 0)
    {
        return INF;
    }

    if (idx == m && val == 0)
    {
        return 0;
    }
    
    

    if (memo[idx][val] == -1)
    {
        memo[idx][val] = min(1 + solve(idx, val - saldo[idx]), solve(idx + 1, val));
    }
    return memo[idx][val];

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> m;
    for (int i = 0; i < m; i++)
    {
       cin >> saldo[i];
    }
    
    cout << solve(0, v) << '\n';
    
    // segmentation fault  e não saber tratar os casos bases

    return 0;
}

// g++ -o nome.cpp nome.exe