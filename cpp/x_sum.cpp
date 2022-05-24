#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


int soma_diagonais(int linha, int coluna, int i, int j, int matriz[210][210]){
    int n, m, sum = 0;
    for ( n = 0; n < linha; n++)
    {
        for ( m = 0; m < coluna; m++)
        {
            if(n + m == i + j || n - m == i - j){
                sum += matriz[n][m];
            }
        }
    }
    return sum;
}


int main(int argc, char const *argv[])
{
    int t, n, m, i, j, max_n;
    int matriz[210][210];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        max_n = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> matriz[i][j];
            }
            
        }
        for ( i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                max_n = max(soma_diagonais(n, m, i, j, matriz), max_n);
            }
        
        }
        cout << max_n << '\n';
    }
    
    return 0;
}

// g++ -o nome.cpp nome.exe