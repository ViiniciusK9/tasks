#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

const long long mod = 1e9+7;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x;
    long long sum_array;
    long long ans;
    cin >> t;
    long long array[212345];

    while (t--)
    {
        cin >> n >> x;

        
        sum_array = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
            sum_array = (((sum_array + array[i]) % mod ) + mod) % mod;
            //DBG(array[i]);
        }
        

        long long best = 0, sum = 0, best_cp = 0;
        for (int k = 0; k < n; k++)
        {
            sum = max(array[k], sum + array[k]);
            best = max(best, sum);
        }
        best_cp = best;
        //cout << best << '\n';

        

        for (int i = 0; i < x; i++)
        {
            best = (((best << 1) % mod ) + mod) % mod;
        }


        ans = (((best + sum_array) % mod ) + mod) % mod;

        ans = (((ans - best_cp) % mod ) + mod) % mod;

        cout << ans << '\n';
        


        

    }
    

    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome