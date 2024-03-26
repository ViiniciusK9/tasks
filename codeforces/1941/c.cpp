#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, ans;
    cin >> t;
    string s;

    while (t--)
    {
        cin >> n;
        cin >> s;
        ans = 0;
        for (int i = 0; i < n-2; i++)
        {
            if ((s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e') || (s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p')) ans++;
            if(i + 4 < n) {
                if (s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p' && s[i+3] == 'i' && s[i+4] == 'e') {
                    ans--;
                }
            }
        }
        cout << ans << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome