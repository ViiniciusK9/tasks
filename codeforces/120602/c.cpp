#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

string s[11];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, ans;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 10; i++)
        {
            cin >> s[i];
        }
        ans = 0;
        int ii, jj;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                //cout <<((5 - (i % 5))) << ' ';
                if (s[i][j] == 'X')
                {
                    if (i <= 4)
                    {
                        ii = ((i + 1) % 6);
                    } else
                    {
                        ii = ((5 - (i % 5)));
                    }
                    if (j <= 4)
                    {
                        jj = ((j + 1) % 6);
                    }
                    else
                    {
                        jj = ((5 - (j % 5)));
                    }
                    ans += min(ii , jj);  
                }
            }
        //  cout << '\n';
        }
        cout << ans << '\n';
        
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome