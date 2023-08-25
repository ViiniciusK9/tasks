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
int value[MAX];
 
int solve_dp(int x){
 
    if (x < 0)
    {
        return INF;
    }
    if (x == 0)
    {
        return 0;
    }
 
    if (ready[x])
    {
        return value[x];
    }
    
    int best = INF;
 
    for (auto c : list1)
    {
        best = min(best, solve_dp(x - c) + 1);
    }
 
    value[x] = best;
    ready[x] = true;
    return best;
}
 
 
int main(int argc, char const *argv[])
{
    int n, x, aux, res;
    cin >> n >> x;
 
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        list1.push_back(aux);
    }
 
    res = solve_dp(x);
 
    if (res == INF)
    {
        cout << "-1\n"; 
    } else {
        cout << res << endl;
    }
    return 0;
}
 
// g++ -o nome.cpp nome.exe