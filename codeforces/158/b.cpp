#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, i1, i2, i3, i4, ans;
    cin >> n;
    i1 = i2 = i3 = i4 = ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux == 1) {
            i1++;
        }
        if (aux == 2) {
            i2++;
        }
        if (aux == 3) {
            i3++;
        }
        if (aux == 4) {
            i4++;
        }
    }
    
    ans += i4;

    if (i1 >= i3) {
        ans += i3;
        i1 = i1 - i3;
    } else {
        ans += i3;
        i1 = 0;
    }

    ans += (i1 + (i2 * 2)) / 4;
    if ((i1 + (i2 * 2)) % 4 != 0) ans++;

    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome