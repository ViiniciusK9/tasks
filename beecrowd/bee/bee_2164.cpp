#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


double solve(int n){
    return (pow(((1 + sqrt(5))/2), n) - pow(((1 - sqrt(5))/2), n)) / (sqrt(5));
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << F(solve(n)) << '\n';

    return 0;
}

// g++ -o nome.cpp nome.exe