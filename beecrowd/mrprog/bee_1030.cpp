#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nc, n, k;
    cin >> nc;
    while (nc--)
    {
        cin >> n >> k;
        set<int> myset;
        for (int i = 1; i <= n; i++)
        {
            myset.insert(i);
        }
        int aux = k;
        for (int i = 0; i < n-1; i++)
        {
            cout << aux << '\n';
            aux = (aux + k) % n;

        }
        
        
    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe