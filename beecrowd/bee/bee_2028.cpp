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
    int n, x = 1, num;
    while (cin >> n)
    {
        if (n != 0)
        {
            num = (1 + n) * n / 2 + 1;
            cout << "Caso " << x << ": " << num << " numeros\n";
            cout << "0 "; 
        } else {
            num = 1;
            cout << "Caso " << x << ": " << num << " numero\n";
            cout << "0 "; 
        }
        
        
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i << " ";
            }
        }
        
        x++;
        cout << "\n\n";
        // presentation error
    }
    
    return 0;
}

// g++ -g -O2 -std=gnu++17 -static bee_1827.cpp