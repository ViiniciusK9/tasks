#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, m, ans;
    vector<int> vet;
    cin >> t;

    while (t--)
    {
        vet.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet.push_back(aux);
        }
        sort(vet.begin(), vet.end());

        m = n / 2;
        if (n%2 != 0) m++;
        m--;
        ans = 1;
        while (m+1 < n && vet[m] == vet[m+1])
        {
            ans++;
            m++;
        }
        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome