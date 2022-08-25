#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

void remove_equals(int* vet, int n){

}

int main(int argc, char const *argv[])
{
    int n, tam;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tam;
        int aux;
        set<int> vet;
        for (int j = 0; j < tam; j++)
        {
            cin >> aux;
            vet.insert(aux);
        }
        int aux_n = 0;
        int cout_aux = 0;
        for (set<int>::iterator it=vet.begin(); it!=vet.end(); ++it){
            //cout << *it << " ";
            
            if (aux_n > *it)
            {
                cout_aux++;
            }
            aux_n = *it;
            //DBG(cout_aux);
        }
        //cout << "\n";
        
        int result = vet.size() - cout_aux;
        //DBG(vet.size());
        if(result % 2 != tam % 2){
            result--;
        }
        //DBG(result);
        cout << result << '\n';
        
        
        
        

    }
    
    return 0;
}

// g++ -o nome.cpp nome.exe