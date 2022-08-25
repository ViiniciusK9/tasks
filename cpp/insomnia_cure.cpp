#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int k, l, m, n, d;
    set<int> s;

    cin >> k >> l >> m >> n >> d;

    if (k == 1 || l == 1 || m == 1 || n == 1)
    {
        cout << d << '\n';
    } else {
        for (int i = k; i <= d; i += k)
        {
            s.insert(i);
        }
        for (int i = l; i <= d; i += l)
        {
            s.insert(i);
        }
        for (int i = m; i <= d; i += m)
        {
            s.insert(i);
        }
        for (int i = n; i <= d; i += n)
        {
            s.insert(i);
        }
        
        cout << s.size() << '\n';
    }
    
    return 0;
}

// g++ -o nome.cpp nome.exe