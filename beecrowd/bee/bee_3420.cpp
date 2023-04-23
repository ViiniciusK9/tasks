#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX (int)10e18 / 3

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long ult = 0, aux;
    vector<long long> vet;
    long long n = 1;
    while (ult <= MAX && ult >= 0)
    {
        ult = n * (n+1) / 2;
        //ult += (n-1) + (n * 2);
        n++;
        vet.push_back(ult);
    }
    //cout << ult << '\n';

    int t;
    cin >> t;
    while (t--)
    {
        cin >> aux;
        vector<long long>::iterator card = upper_bound(vet.begin(), vet.end(), aux/3);
        //cout << aux << '\n';
        DBG(vet[card - vet.begin()]);
        long long cards = card - vet.begin();
        //DBG(cards);
        //DBG(vet[card - vet.begin()-1] * 3 - (card - vet.begin()));
        if (vet[card - vet.begin()-1] * 3 - (card - vet.begin())  <= aux)
        {
            cout << cards +1 << '\n';
        } else {
            cout << cards << '\n';
        }
        
        
    }

    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome