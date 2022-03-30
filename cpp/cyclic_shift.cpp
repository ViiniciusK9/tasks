#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int bin_to_dec(int bin)
{
    int total  = 0;
    int potenc = 1;

    while(bin > 0) {
        total += bin % 10 * potenc;
        bin    = bin / 10;
        potenc = potenc * 2;
    }

    return total;
}


int main(){
	int t, n, k, i;
    
    cin >> t;
    while (t)   
    {
        int maior = 0, aux, contador = 0;
        cin >> n >> k;
        char  b[n+2] = ("0");
        string a, aux_s;
        cin >> a;
        aux_s = a;
        for(i = 0; i < n; i++){
            maior = max(bin_to_dec(stoi(a)),maior);
            a = a.substr(1, n) += a[0];
        }
    
        while(k){
            aux_s = aux_s.substr(1, n) += aux_s[0];
            if(bin_to_dec(stoi(aux_s)) == maior){
                k--;
            }
            contador ++;
        }
        cout << contador << '\n';

        t--;
    }
    
	return 0;
}
// g++ -o teste Teste.cpp
// ./teste