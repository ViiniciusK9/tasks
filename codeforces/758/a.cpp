#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0, m = 0, aux;
    vector<int> vet;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet.push_back(aux);
        m = max(aux, m);
    }

    for (int i = 0; i < n; i++)
    {
        ans += abs(vet[i] - m);
    }

    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome