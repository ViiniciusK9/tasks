#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
int n;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i = 0, ans = 0;
    cin >> n;
    if (n == 2 || n == 4)
    {
        cout << n << '\n';
    }else {
        while (i != 1)
        {
            ans++;
            if (i == 0)
            {
                i = 2;
            } else {
                i = ((i * 2) > n ? (((i * 2) % n) == 0 ? n-1 : ((i * 2) % n) -1 ) : (i * 2));
            }
            //cout << i << "\n";
        }
        cout << ans << '\n';
    }
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome