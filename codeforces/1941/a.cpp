#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> b;
    vector<int> c;
    int t, n, m, k, aux, ans;
    cin >> t;
    while (t--)
    {
        b.clear();
        c.clear();
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            b.push_back(aux);
        }

        for (int i = 0; i < m; i++)
        {
            cin >> aux;
            c.push_back(aux);
        }
        

        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] >= k) break;
            for (int j = 0; j < m; j++)
            {
                if (b[i] + c[j] <= k) ans++;
                else break;
            }
        }

        cout << ans << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome