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

    int a, b, c, n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        if (a >= b && a >= c)
        {
            if (a == b + c)
            {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            
        }
        else if (b >= a && b >= c)
        {
            if (b == a + c)
            {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            
        }
        else if (c >= b && c >= a)
        {
            if (c == b + a)
            {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            
        }
    }
    
    

    return 0;
}

// g++ -o nome.cpp nome.exe