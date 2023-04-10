#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(2)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p, qnt;
    double price, ans;
    string f;
    
    map<string, double> fruit;

    cin >> n;

    while (n--)
    {
        ans = 0;
        cin >> m;
        while (m--)
        {
            cin >> f >> price;
            fruit[f] = price;
        }
        cin >> p;

        while (p--)
        {
            cin >> f >> qnt;
            ans += fruit.find(f)->second * qnt;
        }
        
        cout << "R$ " << F(ans) << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome