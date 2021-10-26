#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


int times(int argc, char const *argv[])
{
    int p, s, num, num2;
    vector <pair<int, int>> vet;
    cin >> p >> s;
    for(int i = 0; i < s; i++){
        cin >> num >> num2;
        vet.push_back(make_pair(num, num2));
    }
    
    return 0;
}