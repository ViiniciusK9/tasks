#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


int buscaBinaria (int x, int n, int v[]) { 
   int e = -1, d = n; // atenção!
   while (e < d-1) {  
      int m = (e + d)/2;
      if (v[m] < x) e = m;
      else d = m; 
   }
   return d;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vet[10000];

    int n, q, aux, ca = 1;

    while (cin >> n >> q)
    {
        if (n == 0 and q == 0)
        {
            break;
        }
        
        cout << "CASE# " << ca << ":\n";
        ca++;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];
        }
        sort(vet, vet+n);
        for (int i = 0; i < q; i++)
        {
            cin >> aux;
            if (binary_search(vet, vet+n, aux))
            {
                cout << aux << " found at " <<  buscaBinaria(aux, n, vet) +1 << '\n';
            }else {
                cout << aux << " not found\n";
            }
            
        }
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome