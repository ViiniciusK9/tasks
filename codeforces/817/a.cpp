#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2, x, y, ax, ay;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x >> y;
    ax = abs(x1 - x2);
    ay = abs(y1 - y2);
    if (ax % x == 0 && ay % y == 0)
    {
        if (ax == 0 && (ay / y) % 2 == 0)
        {
            cout << "YES\n";
        }
        else if (ay == 0 && (ax / x) % 2 == 0)
        {
            cout << "YES\n";
        }
        else if ((ay / y) % 2 == 0 && (ax / x) % 2 == 0)
        {
            cout << "YES\n";
        }
        else if ((ay / y) % 2 != 0 && (ax / x) % 2 != 0)
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome