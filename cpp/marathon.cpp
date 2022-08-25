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
    int n, a, b, c, d;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        cin >> a >> b >> c >> d;
        if (b > a)
        {
            count++;
        }
        if (c > a)
        {
            count++;
        }
        if (d > a)
        {
            count++;
        }
        cout << count <<'\n';
        
    }
    
    
    return 0;
}

// g++ -o nome.cpp nome.exe