#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, aux;
    //vector<int> vet;
    //vet.reserve(112345);
    cin >> n >> m;

    long long ans = 0;
    int ant = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        if (ant <= aux) {
            ans += abs(aux-ant);
        } else {
            ans += abs(ant - n) +1;
            ans += abs(1 - aux);
        }
        ant = aux;
        //vet.push_back(aux);
    }
    cout << ans << '\n';
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome