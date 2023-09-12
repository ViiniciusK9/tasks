#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    string mat[8];
    cin >> n;
    for (int x = 0; x < n; x++)
    {

        for (int i = 0; i < 8; i++)
        {
            cin >> mat[i];
            
        }
        
        
        int k = 0;
        for (int i = 0; i < 8; i++)
        {
            if (mat[i][0] != '.')
            {
                int t = 0;
                for (int j = 0; j < 8; j++)
                {
                    if (mat[i][j] == 'R')
                    {
                        t++;
                    }
                    
                }
                if (t == 8)
                {
                    k = 1;
                }
            }
            if (k == 1)
            {
                cout << "R" << '\n';
                break;
            }
        }
        if (k == 0)
        {
            cout << "B" << '\n';
        }
        
    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe