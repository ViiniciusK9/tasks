#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 10e3+9;

int n, m;
int vet[MAX];
int memo[MAX];


int dp(int q, int i)
{
    if ((q % n) != 0)
    {
        return -MAX;
    } else {
        
    }


}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> vet[i];
        }
        memset(memo, -1, sizeof(memo));

        cout << dp(0, 0) << '\n';
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome