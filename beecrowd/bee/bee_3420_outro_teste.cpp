#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX (long long)10e17

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long aux, ult = 0;
    vector<long long> vet;
    long long n = 1;
    while (ult <= MAX && ult >= 0)
    {
        ult = n * (3 * n + 1) / 2;
        n++;
        vet.push_back(ult);
    }
    //cout << LONG_LONG_MAX << '\n';
    cout << n << '\n';
    int t;
    cin >> t;
    while (t--)
    {
        cin >> aux;
        vector<long long>::iterator card = lower_bound(vet.begin(), vet.end(), aux);
        long long cards = card - vet.begin();
        if ((cards * (3 * cards + 1) / 2) < aux) {
            if (((cards+1) * (3 * (cards+1) + 1) / 2) <= aux)
            {
                cards++;
            }
            
        }
        cout << cards << '\n';
    }

    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome