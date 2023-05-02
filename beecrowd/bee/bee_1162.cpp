#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 51


int vet[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, aux, ans;
    cin >> n;
    while (n--)
    {
        cin >> l;
        ans = 0;
        for (int i = 0; i < l; i++)
        {
            cin >> vet[i];
        }
        
        for (int i = 0; i < l; i++)
        {
            for (int k = 0; k < l-1; k++)
            {
                if (vet[k] > vet[k+1]) {
                    aux = vet[k];
                    vet[k] = vet[k+1];
                    vet[k+1] = aux;
                    ans++;
                }   
            }
            
        }
        //cout << "A troca de trem ideal leva " << ans << ((ans == 1) ? " troca.\n" : " trocas.\n");
        cout << "Optimal train swapping takes " << ans << " swaps.\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome