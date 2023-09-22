#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 11234

typedef long long ll;

int memo[MAX];
int lisMax = 0;
int vet[MAX];
int a[MAX];

// Implementação (top-down) O(n²)
int lis_top_down(int i)
{
    if (memo[i] != -1) return memo[i];

    memo[i] = 1;

    for (int j = 0; j < i; j++)
    {
        if (vet[j] <= vet[i])
            memo[i] = max(memo[i], lis_top_down(j) + 1);
    }

    lisMax = max(lisMax, memo[i]);
    return memo[i];
}

// Implementação bottom-up O(n²)
int lis_bottom_up(int n)
{
    int memo[n], lisMax = 0;
    for (int i = 0; i < n; i++)
    {
        memo[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] <= a[i])
                memo[i] = max(memo[i], memo[j] + 1);
        }
        lisMax = max(lisMax, memo[i]);
    }
    return lisMax;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome