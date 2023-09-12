#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, aux, kk;
    long long int sum, sum1, sum2;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        kk = k;
        sum = 0; sum1 = 0; sum2 = 0;
        vector<int> vet;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet.push_back(aux);
        }
        
        sort(vet.begin(), vet.end());
        /*
        int i = 0, j = n-1;
        while (k--)
        {
            if(vet[i] + vet[i+1] > vet[j]){
                j--;
            } else {
                i+=2;
            }
        }
        for (int x = i; x <= j; x++)
        {
            sum1 += vet[x];
        }

        i = 0, j = n;
        for (int x = i; x <= n-ajuda-1; x++)
        {
            sum += vet[x];
        }

        i = 0, j = n;

        */

        for (int i = 0; i < n; i++)
        {
            DBG(vet[i]);
        }
        
        
        for (int x = ((kk*2)-1); x < n; x++)
        {
            DBG(vet[x]);
            sum2 += vet[x];
        }
        

        //cout << ((sum > sum1) ? ((sum > sum2) ? sum : sum2) : ((sum1 > sum2) ? sum1 : sum2)) << '\n';
        cout << sum << " " << sum1 << " " << sum2 << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome