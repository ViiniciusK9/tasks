#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 112345

typedef long long ll;

int n, loc[MAX], bit[MAX];

void setbit(int i, int delta) {
    while (i <= n)
    {
        bit[i] += delta;
        i += i & -i;
    }
}

ll getbit(int i) {
    ll ans = 0;
    while (i)
    {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}




int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int aux;
    while (cin >> n)
    {
        memset(loc, 0, sizeof(loc));
        memset(bit, 0, sizeof(bit));
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            loc[aux] = i+1;
            setbit(i+1, 1);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += getbit(n) - getbit(loc[i]);
            setbit(loc[i], -1); 
        }
        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome