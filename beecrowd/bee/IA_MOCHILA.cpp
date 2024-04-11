#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    pair<double, pair<int, int>> p;
    vector<pair<double, pair<int, int>>> vet;
    double n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        vet.push_back({((a/b)), {a, b}});
    }

    sort(vet.begin(), vet.end());
    reverse(vet.begin(), vet.end());

    int m = 500;
    int valor = 0;
    for (auto i : vet)
    {
        if (m - i.second.second < 0) {
            break;
        } else {
            valor+= i.second.first;
            m -= i.second.second;
        }
        cout << "media: " << i.first << " valor: " << i.second.first << " massa: " << i.second.second << " \n";
    }
    
    cout << "VAlor: " << valor << '\n';
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome