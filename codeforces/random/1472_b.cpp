#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, sum, aux;
    map<int, int> m;
    cin >> t;
    while (t--)
    {
        m.clear();
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            m[aux]++;
        }

        if (m[1] % 2 == 1)
        {
            cout << "NO\n";
        } 
        else if (m[2] != 0 && m[2] % 2 == 0)
        {
            cout << "YES\n";            
        } 
        else if (m[1] != 0 && m[1] % 2 == 0)
        {
            cout << "YES\n";  
        }
        else 
        {
            aux = m[1] / 2;
            m[2]+= aux;
            if (m[2] % 2 != 0)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome