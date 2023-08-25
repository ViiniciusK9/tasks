#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
 
using namespace std;
 
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
 
 
const int MAX = 10e6 + 2;
const int INF = 10e7 - 1;
 
std::list<int> list1;
 
int ready[MAX];
long long int value[MAX];
 
/*
int solve_dp(int x, int best){
 
    if (x < 0)
    {
        return 0;
    }
    if (x == 0)
    {
        return 1;
    }
 
    if (ready[x])
    {
        return value[x];
    }
 
    for (auto c : list1)
    {
        best += solve_dp(x - c);
    }
 
    value[x] = best;
    ready[x] = true;
    return best;
}
*/
 
int main(int argc, char const *argv[])
{
    long long int m = 1000000007;
    int n;
    cin >> n;
 
    for (int i = 1; i < 7; i++)
    {
        list1.push_back(i);
    }
 
    //res = solve_dp(n);
 
    value[0] = 1;
    for (int x = 1; x <= n; x++) {
        for (auto c : list1) {
            if (x-c >= 0) {
                value[x] += value[x-c];
                value[x] %= m;
            }
        }
    }
    
    
    cout << value[n] << "\n";
 
    return 0;
}
 
// g++ -o nome.cpp nome.exe