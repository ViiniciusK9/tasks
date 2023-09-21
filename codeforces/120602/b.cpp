#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int vet[14];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n, mm, inx, ans;
    cin >> t;
    while (t--)
    {
        mm = 1000;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
            if (mm > vet[i])
            {
                mm = vet[i];
                inx = i;
            }
        }
        vet[inx]++;
        ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans *= vet[i];
        }
        cout << ans << '\n';
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome