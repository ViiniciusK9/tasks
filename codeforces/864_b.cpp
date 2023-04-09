#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 1234

int mat[MAX][MAX];


/*
    NÃO PASSOU
    NÃO PASSOU
    NÃO PASSOU
    NÃO PASSOU
    NÃO PASSOU
    NÃO PASSOU
    NÃO PASSOU
*/

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, v, i, j, ans;

    
    cin >> t;
    //cout << t << '\n';
    while (t--)
    {
        ans = 0;
        cin >> n >> k;
        //cout << n << k << '\n';
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> v ;
                mat[i][j] = v;
            }
            
        }
        //cout << n << '\n';

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (mat[i][j] != mat[n-1 -i][n-1 -j]) {
                    ans++;
                } 
            }
            
        }
        if (ans <= k)
        {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome