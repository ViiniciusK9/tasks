#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(){
	int t, n, k, aux;
    int vet[1000009];
	cin >> t;
	for(int i = 0; i < t; i++){
        int j = 0;
		cin >> n >> k;
		if(k > n){
			k = k % n;
		}
        j = j+k;
        for(int i = 0; i < n; i++){
            if(j > n-1){
                j = j - n;
            }
            cin >> aux;
            vet[j] = aux;
            j++;
        }
        for(int i = 0; i < n; i++){
            if(i < n-1){
                cout << vet[i] << " ";
            }else {
                cout << vet[i] << '\n';
            }
        }
	}
	
	return 0;
}
// g++ -o teste Teste.cpp
// ./teste