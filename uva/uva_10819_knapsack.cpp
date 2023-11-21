#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int weight[112];
int value[112];
int memo[11234][112];
int m, n;

int dp(int w, int i, int flag)
{
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> m >> n;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    if (m >= 1800) m += 200;
    
    //cout << dp(m, n) << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome