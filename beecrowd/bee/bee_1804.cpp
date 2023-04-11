#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 112345

typedef long long ll;


int n, bit[MAX], aux;

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

void updatebit(int i, int delta) {
    delta = getbit(i) - getbit(i-1);
    while (i <= n)
    {
        bit[i] -= delta;
        i += i & -i;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        setbit(i+1, aux);
    }
    char op;
    int val;
    while (cin >> op)
    {
        cin >> val;
        switch (op)
        {
        case 'a':
            updatebit(val, 0);
            break;
        case '?':
            cout << getbit(val-1) << '\n';

            break;        
        }
    }
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome