#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


int main(){
	int t, n, k, i;
    cin >> t;
    while (t){
        int aux, contador = 0;
        string maior = "";
        cin >> n >> k;
        string a, aux_s;
        cin >> a;
        aux_s = a;
        vector<int> quant;
        // for(i = 0; i < n; i++){
        //     maior = max(bin_to_dec(stoi(a)),maior);
        //     a = a.substr(1, n) += a[0];

        for(i = 0; i < n; i++){
            
            if(a > maior){
                maior = a;
            }
            a = a.substr(1, n) += a[0];
        }

        int xxx = 0;
        for(i = 0; i < n; i++){
            // cout << aux_s << '\n';
            if(aux_s == maior){
                if(quant.size() == 0){
                    quant.push_back(i);
                }else {
                    int prox = i - quant[xxx];
                    quant.push_back(prox);
                    xxx++;
                }
            }
            aux_s = aux_s.substr(1, n) += aux_s[0];
        }

        // for(int i = 0; i < quant.size(); i++){
        //     cout << "i: " << i << " : " << quant[i] << '\n';
        // }

        
        // int i = 0;
        // while(k){
        //     contador += quant[i];
        //     k--;
        //     if(i >= quant.size()-1){
        //         i = 0;
        //         if(k){
        //             contador += 1;
        //         }
        //     }else {
        //         i++;
        //     }
        // }
    
        int total = k / quant.size();
        int resto = k % quant.size();
        // cout << resto << '\n';
        if(total){
            
            total = total * quant[quant.size()-1];
            
        }
        for(int i = 0; i < resto; i++){
            total += quant[i];
        }


        // cout << maior << '\n';
    
        // while(k){
        //     aux_s = aux_s.substr(1, n) += aux_s[0];
        //     if(aux_s == maior){
        //         k--;
        //     }
        //     contador ++;
        // }


        cout << total << '\n';
        // cout << contador << '\n';
        t--;
    }
    
	return 0;
}
// g++ -o teste cyclic_shift.cpp
// ./teste 