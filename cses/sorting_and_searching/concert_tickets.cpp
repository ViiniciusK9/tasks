#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, aux;
    cin >> n >> m;
    vector<int> vet;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet.push_back(aux);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        q.push(aux);
    }
    sort(vet.begin(), vet.end());
    while (!q.empty())
    {
        aux = q.front();
        auto t = lower_bound(vet.begin(), vet.end(), aux);
        
        if (t != vet.end())
        {
            /* code */
        
            cout << vet[t - vet.begin() -1] << '\n';
            if (vet[t - vet.begin()] == aux)
            {
                cout << vet[t - vet.begin()] << '\n';
                vet.erase(t);
            } else {
                cout << vet[t - vet.begin() -1] << '\n';
                vet.erase(t-1);
            }
            
            
            
            for (auto &j : vet)
            {
                cout << j << ' ';
            }
            cout << '\n';
            
        }
        q.pop();
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome