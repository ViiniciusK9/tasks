#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int uri_1040(int argc, char const *argv[])
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


int uri_1049(int argc, char const *argv[])
{
    string p1, p2, p3;

    cin >> p1;
    cin >> p2;
    cin >> p3;

    if (p1 == "vertebrado"){
        if (p2 == "ave"){
            if (p3 == "carnivoro"){
                cout << "aguia" << endl;
            } else {
                cout << "pomba" << endl;
            }
        } else {
            if (p3 == "onivoro"){
                cout << "homem" << endl;
            } else{
                cout << "vaca" << endl;
            }
        }
    } else {
        if (p2 == "inseto"){
            if (p3 == "hematofago"){
                cout << "pulga" << endl;
            } else{
                cout << "lagarta" << endl;
            }
        } else {
            if (p3 == "hematofago"){
                cout << "sanguessuga" << endl;
            } else{
                cout << "minhoca" << endl;
            }
        }
    }

    return 0;
}


int uri_1101(int argc, char const *argv[])
{
    int num, num2, aux;

    while (true)
    {
        int sum = 0;
        cin >> num;
        cin >> num2;
        if (num <= 0 || num2 <=0){
            break;
        }
        if (num > num2){
            aux = num;
            num = num2;
            num2 = aux;
        }
        for (int i = num; i <= num2; i++){
            cout << i << " ";
            sum += i;
        }
        cout << "Sum=" << sum << endl;
    }
    return 0;
}


int uri_1133(int argc, char const *argv[])
{
    int num, num2, aux;
    cin >> num >> num2;

    if (num > num2){
        aux = num;
        num = num2;
        num2 = aux;
    }

    for (int i = (num + 1); i < num2; i++){
        if (i % 5 == 2 or i % 5 == 3){
            cout << i << endl;
        }
    }

    return 0;
}


int uri_1176(int argc, char const *argv[])
{
    int64_t vet[62] = {0, 0, 1};
    int quant;
    cin >> quant;
    int vet2[quant];

    for (int i = 3; i <= 61; i++){
        vet[i] = vet[i-1] + vet[i-2];
    }
    
    for (int i = 0; i < quant; i++){
        cin >> vet2[i];
        cout << "Fib(" << vet2[i] << ") = " << vet[(vet2[i]+1)] << endl;
    }
    return 0;
}