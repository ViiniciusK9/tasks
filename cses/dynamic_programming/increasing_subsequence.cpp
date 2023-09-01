#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 200045


int n;
int vet[MAX];
int memo[MAX];


int solve() // TIME LIMITED EXCEEDED
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vet[j] < vet[i])
            {
                memo[i] = max(memo[i], memo[j]+1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (memo[i] > ans)
        {
            ans = memo[i];
        }
    }
    return ans;
}

// BUSCAR UMA IMPLEMENTAÇÃO N LOG(N)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    for (int i = 0; i < n; i++)
    {
        memo[i] = 1;
    }

    cout << solve() << '\n';


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome