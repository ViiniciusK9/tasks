#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
const long long int MAX = 10000000000;

std::vector<long int> vet(10000000000, -1);

int solve(int n){
    if(vet[n] == -1){
        vet[n] = (solve(n-1) + solve(n-2));
        return vet[n];
    } else {
        return vet[n];
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vet[0] = 0;
    vet[1] = 1;
    vet[2] = 1;
    long int n, m;
    while(cin >> n >> m){
        cout << (solve(solve(n)) % m) << '\n';
    }
    return 0;

    // runtime error
}

// g++ -o nome.cpp nome.exe