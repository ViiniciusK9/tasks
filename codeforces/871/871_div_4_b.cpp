#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 123

int vet[MAX];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, max, ant, at, qnt;
    cin >> t;
    while (t--)
    {
        max = 0;
        qnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> at;
            if (at == 0)
            {
                qnt++;
            } else {
                if (qnt > max)
                {
                    max = qnt;
                }
                
                qnt = 0;
            }
            
        }
        if (qnt > max)
        {
            max = qnt;
        }
        cout << max << '\n';
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome