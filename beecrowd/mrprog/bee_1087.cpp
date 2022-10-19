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

    int x1, y1, x2, y2;

    while (true)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
        {
            break;
        }

        if (x1 == x2 && y1 == y2)
        {   
            cout << "0\n";
        } else if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }

    return 0;
}

// g++ -o nome.cpp nome.exe