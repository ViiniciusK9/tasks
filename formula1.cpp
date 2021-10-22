#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

struct piloto{
    int colocacao[101];
    int pontuacao;
    int id;
};

int func(piloto a, piloto b){
    return a.pontuacao > b.pontuacao;
}

int main(int argc, char const *argv[])
{
    int g, p, s, k, aux;
    cin >> g >> p;
    if (g == 0 && p ==0){
        return 0;
    }
    piloto vet[p];
    for(int i = 0; i < g; i++){
        for(int j = 0; j < p; j++){
            cin >> vet[j].colocacao[g];
            vet[i].id = j+1;
            vet[i].pontuacao = 0;
        }
    }
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            for (int x = 0; x < g; x++){
                for(int y = 0; y < p; y++){
                    if(vet[y].colocacao[x] == j){
                        cin >> aux;
                        vet[y].pontuacao += aux;
                    }
                }
            }
        }
    }
    sort(vet, vet+p);
    for(int i = 0; i < p; i++){
        cout << vet[i].id << " ";
    }
    cout << endl;

    return 0;
}
