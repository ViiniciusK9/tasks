#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, aux, ans = 1;
    cin >> n;
    vector<int> vet;

    for (i = 0; i < n; i++)
    {
        cin >> aux;
        vet.push_back(aux);
    }
    sort(vet.begin(), vet.end());

    for (i = 0; i < n-1; i++)
    {
        if (vet[i] != vet[i+1])
        {
            ans++;
        }
    }
    cout << ans << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome