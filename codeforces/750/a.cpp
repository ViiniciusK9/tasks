#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, h = 240, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if ((k + i * 5) > 240)
        {
            break;
        }
        else
        {
            ans++;
            k += i*5;
        }
    }
    cout << ans << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome