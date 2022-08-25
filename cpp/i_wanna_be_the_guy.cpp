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
    int n, p, aux;
    set<int> s;

    cin >> n;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> aux;
        s.insert(aux);
    }
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> aux;
        s.insert(aux);
    }
    
    if (s.size() != n)
    {
        cout << "Oh, my keyboard!\n";
    } else {
        cout << "I become the guy.\n";
    }
    return 0;
}

// g++ -o nome.cpp nome.exe