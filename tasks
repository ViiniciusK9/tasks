#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    float vet[4];
    float media, exame;

    for (int i = 0; i < 4; i++){
        cin >> vet[i];
    }

    media = ((vet[0] * 2) + (vet[1] * 3) + (vet[2] * 4) + (vet[3])) / 10;
    cout << "Media: " << F(media) << endl;
    if (media >= 7){
        cout << "Aluno aprovado." << endl;
    } else if (media < 5){
        cout << "Aluno reprovado." << endl;
    } else{
        cout << "Aluno em exame." << endl;
        cin >> exame;
        cout << "Nota do exame: " << F(exame) << endl;
        media = (media + exame) / 2; 
        if (media >= 5){
        cout << "Aluno aprovado." << endl;
        } else {
        cout << "Aluno reprovado." << endl;
        }
        cout << "Media final: " << F(media) << endl;
    }
    return 0;
}
