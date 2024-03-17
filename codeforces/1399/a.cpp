#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, ans;
    vector<int> vet;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vet.clear();
        for (int j = 0; j < n; j++)
        {
            cin >> aux;
            vet.push_back(aux);
        }
        sort(vet.begin(), vet.end());

        ans = 1;
        for (int j = 0; j < n-1; j++)
        {
            if (abs(vet[j] - vet[j+1]) > 1) 
            {
                ans = 0;
                break;
            }
        }
        
        cout << ((ans == 1) ? "YES" : "NO") << '\n';
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome