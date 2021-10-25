#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int fact[10];
    fact[0] = 1;
    for(int i = 1; i <= 9; i++){
        fact[i] = i*fact[i-1];
    }
    int n, x = 0, k;
    cin >> n;
    for(int i = 1; i <= 9; i++){
        if(fact[i]>n){
            k = i -1;
            break;
        }
    }
    for(int i = k; i >= 0; i--){
        x += (n/fact[i]);
        n = n % fact[i];
    }
    cout << x << endl;
    return 0;
}
