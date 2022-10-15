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
    int n = 100;
    cout << n << endl;

    for (int i = 1; i < n; i++)
    {
        cout << i << " ";
    }
    
    cout << n << endl;

    return 0;
}

// g++ -o nome.cpp nome.exe