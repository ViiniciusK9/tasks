#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int vet[150009];

long long sum_range(int i, int j)
{
    long long ans = 0;
    for (int x = i; x < j; x++)
    {
        ans += vet[x];
    }
    //DBG(ans);
    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
        }
        
        int i = 2;
        long long ans = 0;
        long long max1 = 0, min = 0, diff = 0, aux;
        while ((n / (double)i) >= 1.0)
        {
            if (n % i == 0)
            {
                int j = n / i;
                max1 = 0; min = 0; diff = 0;
                for (int x = 0; x < n; x+=j)
                {
                    //DBG(x);
                    //DBG(x+j);
                    aux = sum_range(x, x+j);
                    if (x == 0)
                    {
                        max1 = aux;
                        min = max1;
                    }
                    if (aux > max1)
                    {
                        max1 = aux;
                        diff = max(abs(max1 - min), diff);
                    }
                    if (aux < min)
                    {
                        min = aux;
                        diff = max(abs(max1 - min), diff);
                    }
                }
                //DBG(j);
                //DBG(diff);
                ans = max(diff, ans);
            }
            i++;
        }
        
        cout << ans << '\n';
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome