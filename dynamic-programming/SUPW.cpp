#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n], dp[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];

    for (int i = 3; i < n; i++)
    {
        dp[i] = min({dp[i-1], dp[i-2], dp[i-3]}) + a[i];
    }
    
    cout << min({dp[n-1], dp[n-2], dp[n-3]}) << '\n';

    
    /*
    Soma minima para escolher os dias sem deixar 3
    dias consecutivos livres
    
    
    5
    2 2 3 2 2


    */


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome