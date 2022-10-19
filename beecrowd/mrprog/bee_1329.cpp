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

    int n, j, m, aux;
    int vet[10001];
    cin >> n;
    while (n != 0)
    {
        j = 0, m = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (aux == 0)
            {
                m++;
            } else {
                j++;
            }
            
        }
        cout << "Mary won " << m << " times and John won " << j  << " times\n";
        cin >> n;
    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe