#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t, n, a, b;

    cin >> t;
    vector<pair<int, int>> vet;
    while (t--)
    {
        vet.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a >> b;
            if (a <= 10)
            {
                vet.push_back({b, i});
            }
        }
        
        sort(vet.begin(), vet.end());
        cout << vet[vet.size()-1].second << '\n';
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome