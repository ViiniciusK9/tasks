#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(){
    int matrix[10000][10000];
	int t, n, aux;
    cin >> t;
    for(int x = 0; x < t; x++){
        int count = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for (int p = 0; p < n; p++){
                    for (int q = 0; q < n; q++){
                        //if(matrix[i][j]>matrix[p][q]){
                        //    count++;
                        //}
                    }
                }
            }
        }
        cout << count << endl;
    }

	return 0;
}
// g++ -o teste Teste.cpp
// ./teste