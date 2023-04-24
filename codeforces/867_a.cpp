#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, n, t, aux;
    cin >> q ;
    while (q--)
    {
        vector<int> vet1;
        vector<int> vet2;

        cin >> n >> t;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet1.push_back(aux);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet2.push_back(aux);
        }
        int max = 0, i_max = -2;

        for (int i = 0; i < n; i++)
        {
            if (vet1[i] + i <= t && vet2[i] > max)
            {
                max = vet2[i];
                i_max = i;
            }
            
        }
        
        cout << i_max + 1 << '\n';
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome