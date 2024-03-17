#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, sum = 0, ans = 0;
    vector<int> vet;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        sum += aux;
        vet.push_back(aux);
    }

    sort(vet.begin(), vet.end());
    reverse(vet.begin(), vet.end());
    aux = 0;
    for (int i = 0; i < n; i++)
    {
        if (aux > sum) {
            break;
        } else {
            aux+=vet[i];
            sum-=vet[i];
        }
        ans = i;
    }
    cout << ans + 1 << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome