#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

vector<int> vet;
array<array<int, 2060>, 15> memo;
int solve(int n, int i)
{
    if (n == 0) {
        return 0;
    }

    if (n < 0 || i == vet.size()) {
        return 1000000;
    }

    if (memo[i][n] != 0) return memo[i][n];

    memo[i][n] = min({solve(n, i+1), 1 + solve(n-vet[i], i+1), 1 + solve(n+vet[i], i+1)});
    return memo[i][n];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, aux;
    cin >> t;
    
    int i = 1;
    while (i <= 2048)
    {
        vet.push_back(i);
        i = i<<1;
    }

    for (int i = 0; i < 15; i++)
    {
        fill(memo[i].begin(), memo[i].end(), 0);
    }
    
    
    while (t--)
    {
        cin >> aux;
        cout << solve(aux, 0) << '\n';
    }
    

    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome