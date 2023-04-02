#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vet[(int)(10e4+7)];

    int n, m, max, i;
    while (cin >> n)
    {
        m = 0;
        max = -10e5;
        for (i = 0; i < n; i++)
        {
            cin >> vet[i];
            m+=vet[i];
        }

        if ((m % n) != 0)
        {
            cout << "-1\n";
            continue;
        }
        m = m / n;
        max = 0;
        int a = 0;
        for (i = 0; i < n; i++)
        {
            if (abs(m - vet[i]) % 2) {
                a++;
                max += abs(m - vet[i]) / 2;
            } else {
                max += abs(m - vet[i]) / 2;
            }
        }
        max += a / 2;
        cout << max + 1 << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome