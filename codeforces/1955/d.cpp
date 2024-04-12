#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 2 * (1e5 + 5);

array<int, MAX> arr1;
array<int, MAX> arr2;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, k, aux;
    map<int, int> ma;
    map<int, int> maa;
    cin >> t;
    while (t--)
    {
        ma.clear();
        maa.clear();
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
            
            ma[arr2[i]]++;
        }

        for (auto i : ma)
        {
            maa[i.first] = i.second;
        }
        

        for (int i = 0; i < m; i++)
        {
            if (ma.find(arr1[i]) != ma.end() && ma[arr1[i]] > 0) {
                ma[arr1[i]]--;
            }
        }
        long long sum_ma = 0;
        
        for (auto i : ma)
        {
            sum_ma += i.second;
        }
        
        int ans = 0;
        int qnt = (m - sum_ma);
        if (qnt >= k) ans++;

        for (auto i : ma)
        {
            cout << i.second << " ";
        }
        cout << '\n';

        for (int i = m; i < n; i++)
        {
            DBG(i);
            if (ma.find(arr1[i-m]) != ma.end()) {
                if (ma[arr1[i-m]] < maa[arr1[i-m]]){
                    ma[arr1[i-m]]++;
                    sum_ma++;
                    DBG(arr1[i-m]);
                }
            }

            if (ma.find(arr1[i]) != ma.end() && ma[arr1[i]] > 0) {
                ma[arr1[i]]--;
                sum_ma--;
                DBG(arr1[i]);
            }
            qnt = (m - sum_ma);
            DBG(qnt);
            DBG(k);
            if (qnt >= k) ans++;
        }
        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome