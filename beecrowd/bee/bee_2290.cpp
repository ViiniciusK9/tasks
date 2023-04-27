#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, first = 1;
    while (cin >> n)
    {
        if (!first) {
            cout << '\n';
        }
        first = 0;
        set<int> s;
        
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (!s.empty())
            {
                if (s.find(aux)  != s.end()) {
                    s.erase(aux);
                } else {
                    s.insert(aux);
                }
            } else {
                s.insert(aux);
            }
        }
        for (auto &j : s)
        {
            cout << j << " ";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome