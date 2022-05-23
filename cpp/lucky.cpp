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
    int n, i;
    bool result;
    string a;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a;
        result = ((int)a[0] + (int)a[1] + (int)a[2]) == ((int)a[3] + (int)a[4] + (int)a[5]);
        if(result){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
