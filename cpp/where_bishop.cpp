#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int n, ss;

    cin >> n;
    char mat[9];
    for (int i = 0; i < n; i++)
    {
        cin >> ss;
        
        int achou = 0;
        int linha = 0;
        int coluna = 0;
        for (int j = 0; j < 9; j++)
        {
            
            gets (mat);
            //cout << mat << '\n';
            
            for (int x = 0; x < 8-2; x++)
            {
                
                if(mat[x] == '#' && mat[x+1] == '.' && mat[x+2] == '#' && !achou){
                    linha = j + 2;
                    coluna = x + 2;
                    achou = 1;
                    cout << linha << " " << coluna << '\n';
                    break;
                }
                
            }
            
        }
        
        
    }
    
    
    return 0;
}

// g++ -o nome.cpp nome.exe