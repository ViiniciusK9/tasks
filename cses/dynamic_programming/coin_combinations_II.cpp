#include<bits/stdc++.h>
 
using namespace std;
 
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
 
const int M = (int )10e9+7;

int n, num;
int vet[1123456];
int memo[1123456];
 
long long int dp(int w) {
    int min = 0;
    memo[0] = 1;
    for (int x = 1; x <= num; x++)
    {
        for (int i = 0; i < n; i++) 
        {
            if (x - vet[i] >= 0)
            {
                min = vet[i];
                memo[x] += memo[x - vet[i]];
                memo[x] %= M;
            }
        }
    }

    return memo[w];
}
 
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> num;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
 
    sort(vet, vet+n);
    
    cout << dp(num) << '\n';

    for (int i = 0; i <= num; i++)
    {
        cout << memo[i] << ' ';
    }
    
    return 0;
}
 
// g++ -O2 -Wall nome.cpp -o nome