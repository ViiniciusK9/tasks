#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int n, max = 0, aux;
    vector<int> vx;
    vector<int> vy;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vx.push_back(aux);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vy.push_back(aux);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            aux = pow((vx[i] - vx[j]),2) + pow((vy[i] - vy[j]),2);
            if ((aux) > max) {
                max = aux;
            }
        }
    }
    cout << max << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome