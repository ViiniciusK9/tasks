#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(2)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, p, qnt, _case = 1;
    double mid, peo;
    cin >> n;
    while (n)
    {
        if (_case != 1)
        {
            cout << '\n';
        }
        
        vector<pair<int, int>> vet;
        peo = mid = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> p >> qnt;
            mid += qnt;
            peo += p;
            qnt /= p;

            vet.push_back(pair<int, int> (qnt, p));
        }
        cout << "Cidade# " << _case << ":\n";
        _case++;
        int aux = 0;
        sort(vet.begin(), vet.end());
        for (auto &j : vet)
        {
            if (aux == 0)
            {
                cout << j.second << "-" << j.first;
                aux = 1;
            } else {
                cout << " " << j.second << "-" << j.first;
            }
            
            
        }
        cout << '\n';
        cout << "Consumo medio: " << floorf(mid/peo * 100) / 100 << " m3.\n";
        cin >> n;
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome