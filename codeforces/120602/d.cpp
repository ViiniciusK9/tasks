#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        int i = 0, ans = 0;
        while (i < n)
        {
            if (s[i] == 'B')
            {
                ans++;
                i+=k;
            } else i++;
        }
        cout << ans << '\n';
    }
    


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome