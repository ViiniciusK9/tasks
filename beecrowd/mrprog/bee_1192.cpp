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

    int n, n1, n2;
    int s;
    string a;
    cin >> n;

    while (n--)
    {
        cin >> a;
        n1 = ((int) a[0]) - 48;
        s = (int) a[1];
        n2 = ((int) a[2]) - 48;

        if (n1 == n2)
        {
            cout << n1 * n2 << '\n';
        } else {
            if (s < 97)
            {
                cout << n2 - n1 << '\n';
            } else {
                cout << n1 + n2 << '\n';
            }
            
        }
    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe