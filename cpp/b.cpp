#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <string>
#include <type_traits>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int primo(int n)
{
   int d;
   if(n <= 1) return false;
   for (d = 2; d*d <= n; d++) {
     if (n%d == 0)   // d divide n
       return false;
    }
   return true;
}

bool pow2(int n){
    float resultado = log(n) / log(2);
    int a = int(resultado);
    if(resultado - a == 0){
        return true;
    }else {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int n, i, chuva = 0, neve = 0, sol = 0;
    string aux;
    string cor;
    string fitas;
    string mto;
    cin >> n;
    
    
    for(i = 0; i < n; i++){
        cin >> aux;
        if(aux == "Chuva"){
            chuva++;
        }
        if(aux == "Neve"){
            neve++;
        }
        if(aux == "Sol"){
            sol++;
        }
    }
    if(primo(sol)){
        mto = "muitos presentes";
    }else {
        mto = "poucos presentes";
    }
    if(chuva % 2 == 0){
        cor = "rosa";
    }else {
        cor = "laranja";
    }
    if(pow2(neve) || neve == 1){
        fitas = "azul";
    }else {
        fitas = "verde";
    }
    cout << "Nesse ano serão feitos " << mto << ", com embrulho de cor "<< cor << ", e fitas da cor " << fitas << "." << '\n';
    return 0;
}
