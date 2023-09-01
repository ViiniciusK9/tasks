#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1123
#define INF 112345678

int n, x;

int price[MAX], pages[MAX];

int memo[100001];

int solve(int w, int i)
{
    memo[0] = 0;

    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << solve(x, 0) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome