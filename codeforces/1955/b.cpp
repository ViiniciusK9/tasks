#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, c, d, a1, aux, flag;
    vector<int> vet;
    vector<int> vet_;
    cin >> t;

    while (t--)
    {
        cin >> n >> c >> d;
        flag = 1;
        vet.clear();
        vet_.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> aux;
                vet.push_back(aux);
            }
        }

        sort(vet.begin(), vet.end());
        a1 = vet[0];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                aux = ((i * c) + (j * d) + a1);
                vet_.push_back(aux);
            }
        }

        sort(vet_.begin(), vet_.end());

        for (int i = 0; i < vet.size(); i++)
        {
            if (vet_[i] != vet[i])
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome