#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    cin >> n;
    vector<int> vet;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet.push_back(aux);
    }

    sort(vet.begin(), vet.end());

    for (int i = 0; i < n; i++)
    {
        cout << (i == 0 ? "" : " ") << vet[i];
    }
    cout << '\n';   
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome