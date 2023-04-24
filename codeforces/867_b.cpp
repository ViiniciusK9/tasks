#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t, n, aux;
    long long ans;
    cin >> t;
    while (t--)
    {

        cin >> n;
        
        vector<long long> vet;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet.push_back(aux);
        }
        sort(vet.begin(), vet.end());
        ans = max((vet[0] * vet[1]), (vet[vet.size()-2] * vet[vet.size()-1]));
        cout << ans << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome