#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long x;
    vector<long long> vet(112345, 0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    int ans= 0;
    for (int i = 0; i < n; i++)
    {
        ans = 2;
        if (vet[i] == 1 || vet[i] == 2) {
            cout << "NO\n";
            continue;
        }
        
        long long mm = sqrt(vet[i]) +1;
        for (long long j = 2; j <= mm; j++)
        {
            if (vet[i] % j == 0)ans++;
            if (ans > 3) break;
        }
        if (ans == 3) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome