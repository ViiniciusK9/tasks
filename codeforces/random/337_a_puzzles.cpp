#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int vet[51];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m, ans;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> vet[i];
    }
    
    sort(vet, vet+m);
    int j = 0;
    ans = 1000000;
    for (int i = n-1; i < m; i++)
    {
        ans = min(ans, abs(vet[j] - vet[i]));
        j++;
    }
    
    cout << ans << '\n';


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome