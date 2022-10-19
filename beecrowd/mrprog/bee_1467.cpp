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
    int a, b, c;
    while (cin >> a)
    {
        cin >> b >> c;
        if (a == b && b == c)
        {
            cout << "*\n";
        } else if (a == b){
            cout << "C\n";
        } else if (a == c) {
            cout << "B\n";
        } else {
            cout << "A\n";
        }
    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe