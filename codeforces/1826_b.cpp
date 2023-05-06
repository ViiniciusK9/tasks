#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 112345

int vet[MAX];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, m, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> vet[i];
        }
        
        m = 0;
        i = 0;
        j = n-1;
        while (i <= j)
            {
                if (vet[i] == vet[j])
                {
                    i++;
                    j--;
                } else {
                    m = -1;
                    break;
                }
            }

        if (m == 0) {
            cout << m << '\n';
        } else {
            m = abs(vet[0] - vet[n-1]);

            for (i = 0; i < n; i++)
            {
                vet[i] = vet[i] % m;
            }
            i = 0;
            j = n-1;
            while (i <= j)
            {
                if (vet[i] == vet[j])
                {
                    i++;
                    j--;
                } else {
                    i = -1;
                    break;
                }
            }
            if (i == -1)
            {
                m = 1;    
            }
            cout << m << '\n';
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome