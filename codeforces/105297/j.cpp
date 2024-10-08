#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    vi p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    ll qnt = n;
    ll mx = 0;
    ll val = 0;
    for (int i = 0; i < n; i++)
    {
        ll va = p[i];

        //mx = max(va*qnt, mx);

        if (va*qnt > mx) {
            mx = va*qnt;
            val = va;
        }

        qnt--;
    }

    cout << val << " " << mx << '\n';
    
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome