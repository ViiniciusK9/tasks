#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(){
    
	int t, n, aux, contador;
    cin >> t;
    for(int x = 0; x < t; x++){
        contador = 0;
        cin >> n;
        int matrix[n][n];
        for(int g = 0; g < n; g++){
            for(int h = 0; h < n; h++){
                cin >> matrix[g][h];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for (int p = 0; p < n; p++){
                    for (int q = 0; q < n; q++){
                        if(matrix[i][j]>matrix[p][q] && i <=p && j <= q){
                            contador++;
                        }
                    }
                }
            }
        }
        cout << contador << '\n';
    }

	return 0;
}
// g++ -o teste Teste.cpp
// ./teste