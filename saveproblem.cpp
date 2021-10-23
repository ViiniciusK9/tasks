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


<<<<<<< HEAD












































































































int uri_1133(int argc, char const *argv[])
{
    int num, num2, aux;

    cin >> num;
    cin >> num2;

    if (num > num2){
        aux = num;
        num = num2;
        num2 = aux;
    }

    for (num + 1; num < num2; num++){
        if (num % 5 == 2 || num % 5 == 3){
            cout << num << endl;
        }
    }
    return 0;
}


int uri_1176(int argc, char const *argv[])
{
    int64_t vet[60] = {0, 1};

    for (int i = 2; i <= 60; i++){
        vet[i] = vet[i-1] + vet[i-2];
    }
    int quant;
    cin >> quant;
    int vet2[quant];
    for (int i = 0; i < quant; i++){
        cin >> vet2[i];
        cout << "Fib(" << vet2[i] << ") = " << vet[vet2[i]] << endl;
    }
    return 0;
}


int uri_matriz123()
{
    int n;
    while (cin >> n)
    {
        int vet[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                if ((i + j) == n - 1){
                    vet[i][j] = 2;
                } else if (i == j){
                    vet[i][i] = 1; 
                } else {
                    vet[i][j] = 3;
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                cout << vet[i][j];
            }
            cout << endl;
        }
    }   
    return 0;
}


int uri_1557(int argc, char const *argv[])
{
    int n, c;

    cin >> n;
    while (n){
        c = 1;
        int vet[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                vet[i][j] = pow(2, i+j);
            }
            
        }
        int num = pow(2, (n-1) + (n-1));

        while (num !=0)
        {
            num /= 10;
            c++;
        }
        

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                if (j != 0) {
                    cout << setw(c) << vet[i][j];
                } else{
                    cout << setw(c-1) << vet[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
        cin >> n;
    } 
    return 0;
}


int codcad(int argc, char const *argv[])
{
    int n, poszero;
    cin >> n;
    int vet[n];

    for (int i = 0; i < n; i++){
        cin >> vet[i];
    }
    for (int i = 0; i < n; i++){
        if (vet[i] == 0)
        {
            poszero = i;
            for (int i = 0; i < n; i++)
            {
                if (vet[i] != 0 && abs(poszero - i) < vet[i] || vet[i] == -1){
                    if (abs(poszero - i) >= 9){
                        vet[i] = 9;
                    } else{
                        vet[i] = abs(poszero - i);
                    }
                }   
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n-1){
            cout << vet[i] << endl;
        } else{
            cout << vet[i] << " ";
        }
    }
=======
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

>>>>>>> 2b68100282e32b637de4ed42d45ac40abfd280e0
    return 0;
}


<<<<<<< HEAD
int matrizmagica(int argc, char const *argv[])
{
    int n, sum = 0, sl = 0, sc = 0, teste = 0, dp = 0, ds = 0;
    cin >> n;
    int matriz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        sum += matriz[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        sl = 0;
        sc = 0;
        for (int j = 0; j < n; j++)
        {
            if(i == j){
                dp += matriz[i][j];
            }
            if ( i + j == n -1){
                ds += matriz[i][j];
            }
            sl += matriz[i][j];
            sc += matriz[j][i];
        }
        if (sl != sum || sc != sum){
            teste = 1;
        }
    }
    if (dp != sum || ds != sum){
        teste = 1;
    }
    if (teste == 1){
        cout << -1 << endl;
    } else{
        cout << sum << endl;
=======
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
>>>>>>> 2b68100282e32b637de4ed42d45ac40abfd280e0
    }
    return 0;
}


<<<<<<< HEAD
int torrecodcad(int argc, char const *argv[])
{
    int n, sl = 0, sc = 0, maior = 0, soma = 0;
    cin >> n;
    int matriz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sl = 0;
            sc = 0;
            if (i == 0 && j == 0){
                for (int t = 0; t < n; t++)
                {
                    sl += matriz[i][t];
                    sc += matriz[t][j];
                    soma = sl + sc - (matriz[i][j] * matriz[i][j]);
                    maior = soma;
                }
            } else{
                for (int t = 0; t < n; t++)
                {
                    sl += matriz[i][t];
                    sc += matriz[t][j];
                    soma = (sl + sc) - (matriz[i][j] + matriz[i][j]);
                }
            }
            if (soma > maior){
                maior = soma;
            }
        }
        
    }
    cout << maior << endl;
=======
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

>>>>>>> 2b68100282e32b637de4ed42d45ac40abfd280e0
    return 0;
}


<<<<<<< HEAD
// Algoritmo da torre de hanoi recursivo.
int hanoi(int n){
    if (n == 1){
        return 1;
    }
    return 2*hanoi(n-1) + 1;
}

int main(int argc, char const *argv[])
{
    int n;
    int c = 1;
    while (true)
    {
        cin >> n;
        if (n == 0) {
            break;
        }
        int resposta = hanoi(n);
        cout << "Teste " << c << endl;
        cout << resposta << endl;
        cout << endl;
        c++;
    }
    
    return 0;
} 
=======
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
>>>>>>> 2b68100282e32b637de4ed42d45ac40abfd280e0
