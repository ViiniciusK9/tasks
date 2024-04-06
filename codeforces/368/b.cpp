#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 112345;

array<int, MAX> arr;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vet;
    set<int> s;

    int n, m, aux;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet.push_back(aux);
    }

    for (int i = n-1; i >= 0; i--)
    {
        s.insert(vet[i]);
        arr[i+1] = s.size();
    }

    while (m--)
    {
        cin >> aux;
        cout << arr[aux] << '\n';

    }
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome