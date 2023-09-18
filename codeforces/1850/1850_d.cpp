#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 212345


int vet[MAX];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
        }
        sort(vet, vet+n);

        int ant = vet[0];
        ans = 1;
        int m1 = 0;
        for (int i = 1; i < n; i++)
        {
            if (abs(ant - vet[i]) > k) 
            {
                //DBG(abs(ant - vet[i]));
                m1 = max(m1, ans);
                ans = 1;
                ant = vet[i];
            }
            else
            {
                ans++;
                ant = vet[i];
            } 
        }
        m1 = max(m1, ans);
        cout << n-m1 << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome