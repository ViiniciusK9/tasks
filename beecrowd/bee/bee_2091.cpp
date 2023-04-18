#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 10^12+7

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long aux;
    while (cin >> n)
    {
        set<long long> c;
        if (n == 0)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (c.find(aux) != c.end()) {
                c.extract(aux);
            } else {
                c.insert(aux);
            }
        }
        for (auto &j : c)
        {
           cout << j << '\n';
        }
    }
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome