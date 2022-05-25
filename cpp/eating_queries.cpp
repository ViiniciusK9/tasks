#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


bool myfunction (int i,int j) { return (i>j); }


void busca_lenta(vector<int> &vet, int n, int busca){
    int achou = 0, lugar = 0;;
    
    for (int i = 0; i < n; i++)
    {
        if(vet[i] >= busca){
            achou = 1;
            lugar = i;
            break;
        }
    }
    if(achou){
        cout << lugar +1 << '\n';
    }else {
        cout << "-1\n";
    }
}


void busca(vector<int> &vet, int n, int busca){
    //print(vet, n);
    int achou, inicio, meio, fim, lugar_achado, final_maior = 0, tem;
    achou = 0;
    lugar_achado = 0;
    inicio = 0;
    fim = n-1;
    meio = ((inicio + fim) / 2);
    while(inicio <= fim && achou == 0){
        if(vet[meio] == busca){
            achou = 1;
            lugar_achado = meio;
        }else {
            if(busca < vet[meio]){
                fim = meio -1;
                tem = 1;
                final_maior = meio;
            }else {
                inicio = meio +1;
            }
            meio = ((inicio + fim) / 2);
        }
    }
    if(achou){
        cout << lugar_achado + 1 << '\n';
    } else if (vet[final_maior] > busca){
        cout << final_maior + 1 << '\n';
    }else {
        cout << "-1\n";
    }
}


int main(int argc, char const *argv[])
{
    int t, n, q, i, aux_q, sum;
    int vet[150009];
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        sum = 0;
        for (i = 0; i < n; i++)
        {
           cin >> vet[i];
        }
        vector<int> myvector (vet, vet+n);
        sort(myvector.begin(), myvector.end(), myfunction);

	    for ( i = 0; i < n; i++)
        {
            sum += myvector[i];
            myvector[i] = sum;
        }
        
        for (i = 0; i < q; i++)
        {
            cin >> aux_q;

            // buscando o numero digitado no vetor
            //print(vet, n);
            //cout << '\n';
            //cout << aux_q << '\n';
            busca(myvector, n, aux_q);
            
        }
    }
    
    
    return 0;
}

// g++ -o nome.cpp nome.exe