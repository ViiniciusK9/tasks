#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(10)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, aux, ant;
    vector<int> vet;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet.push_back(aux);
    }
    
    sort(vet.begin(), vet.end());

    double ma = 0;
    ant = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (i == 0 && vet[i] != 0) {
            ma = vet[i];
        }else {
            ma = max(ma, (abs(ant - vet[i])/2.0));
            ma = max(ma, (abs(vet[i] - vet[i+1])/2.0));
        }
        if (i+1 == n-1) {
            ma = max(ma, abs(l - vet[i+1])/1.0);
        }
        //ma = max({ma, abs(vet[i] - ant), abs(vet[i] - vet[i+1])});
        ant = vet[i];
    }
    if (n == 1) {
        if (vet[0] == 0 || vet[0] == l) {
            ma = l;
        } else {
            ma = max(abs(vet[0])/1.0, abs(l - vet[0])/1.0);
        }
        cout << F(ma) << '\n';
    } else {
        cout << F(ma) << '\n';
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome