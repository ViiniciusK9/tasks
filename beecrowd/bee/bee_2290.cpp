#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, aux;
    while (cin >> n)
    {
        set<long long> s;
        
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
        int ff = 0;
        for (auto &j : s)
        {
            if (!ff)
            {
                cout << j << " ";
                ff = 1;
            } else {
                cout << j << '\n';
            }
            
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome