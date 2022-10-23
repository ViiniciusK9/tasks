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
    int n, tam;
    while (cin >> n)
    {
        tam = n / 3;
        int aux = n - tam;
        string s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j && (i > aux - 1 || i < tam))
                {
                    s = "2";
                } else if ((i + j) == n - 1 && (i > aux - 1 || i < tam)) {
                    s = "3";
                } else if (i == n / 2 && j == n / 2){
                    s = "4";
                } else if (i >= tam && i <= aux - 1 && j >= tam && j <= aux - 1){
                    s = "1";
                } else {
                    s = "0";
                }
                
                cout << s;
                
                
            }
            cout << '\n';
           
        }
        cout << "\n"; 
        
    }
    return 0;
}

// g++ -g -O2 -std=gnu++17 -static bee_1827.cpp