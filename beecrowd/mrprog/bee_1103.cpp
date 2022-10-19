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


    int h1, m1, h2, m2;

    while (true)
    {
        int m, h;
        cin >> h1 >> m1 >> h2 >> m2;
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
        {
            break;
        }

        else if (m1 < m2) {
            m = m2 - m1;
        } else {
            m = abs(60 - m1) + m2;
            h1++;
        }

        if (h1 == 24){
            h1 = 0;
        }

        if (h1 == h2)
        {
            if (m2 < m1)
            {
                h = 24;
            } else {
                h = 0;
            }
        } else if (h1 < h2) {
            h = h2 - h1;
        } else {
            h = abs(24 - h1) + h2;
        }
        if (h1 == h2 && m1 == m2)
        {
            h = 23;
            m = 60;
        }
        
        cout << h * 60 + m << '\n';
        
    }

    return 0;
}

// g++ -o nome.cpp nome.exe