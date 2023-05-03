#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 100001

long long ans;
int vet[MAX];
bool comp(int a, int b) {
    if (a > b)
    {
        ans++;
        return a > b;
    }
    return a > b;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
    for (int i = 0; i < MAX; i++)
    {
        vet[i] = i+1;
    }
    */
    

    int n, aux;

    while (cin >> n && n != 0)
    {
        ans = 0;
        int ans_1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet[i] = aux;
            ans_1 += abs(aux - (i+1)) % 2;
            ans +=   abs(aux - (i+1)) / 2;
            
        }
        
        //DBG(ans);
        /*
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                if (vet[j] > vet[j+1])
                {
                    aux = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = aux;
                    ans++;
                }
                
            }
            
        }
        */

        //DBG(ans);
        cout << (ans + (ans_1 / 2)) << '\n';
        cout << (ans) << '\n';
        //sort(vet, vet+n, comp);
        cout << (ans % 2 == 1 ? "Marcelo\n" : "Carlos\n");

    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome