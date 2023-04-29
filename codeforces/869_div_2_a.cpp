#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 111

int mt[MAX][MAX];

int kk[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, ans, p;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < k; j++)
            {
                mt[i][j] = s[j];
            }
        }
        memset(kk, 0, sizeof(kk));
        for (int i = 0; i < k; i++)
        {
            p = mt[0][i];
            for (int j = 0; j < n; j++)
            {
                if (mt[j][i] != p)
                {
                    kk[j] = 1;
                }
            }
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (kk[i] == 0)
            {
                ans++;
            }
        }
        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome