#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 1000000

int n, k;

int rad[MAX];
int val[MAX];
int memo[MAX];
int aux[MAX];

int dp_1()
{
    memo[MAX-1] = aux[MAX-1];

    for (int i = MAX - 2; i >= 0; i--) {
        if (i + k + 1 >= MAX)
            memo[i] = max(aux[i], memo[i + 1]);
        else
            memo[i] = max(aux[i] + memo[i + k + 1], memo[i + 1]);
    }
 
    return memo[0];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {   
        memset(aux, 0, sizeof(aux));
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> rad[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }

        for (int i = 0; i < n; i++)
        {
            aux[rad[i]-1] = max(val[i], aux[rad[i]-1]);
        }

        memset(memo, -1, sizeof(memo));
        
        k = k-1;
        cout << dp_1() << '\n';
    }
    
    return 0;

}

// g++ -O2 -Wall nome.cpp -o nome