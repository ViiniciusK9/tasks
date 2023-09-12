#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long sum_vet[212345];
    

    long long t, n, q, l, r, k, ant, num, ans;
    cin >> t;
    while (t--)
    {
        //DBG(t);
        sum_vet[0] = 0;
        ant = 0;
        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            sum_vet[i] = sum_vet[ant] + num;
            ant = i;
        }
        while (q--)
        {
            //DBG(q);
            ans = 0;
            cin >> l >> r >> k;
            l--;
            r--;
            if (l > 0)
            {
                ans += sum_vet[l-1];
            }
            if (r < n-1)
            {
                ans += (sum_vet[n-1] - sum_vet[r]);
            }
            ans += (r - l + 1) * k;
            
            if (ans % 2 == 0)
            {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome