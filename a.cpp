#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <stack>
#include <string>
#include <set>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int n, a1, b1, aa, bb;
    string a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        a1 = a.size();
        b1 = b.size();
        aa = 0;
        bb = 0;
        for(int j = 0; j < (a1+b1); j++){
            if(j % 2 == 0){
                if(aa <= a1){
                    cout << a[aa];
                    aa++;
                }else{
                    cout << b[bb];
                    bb++;
                }
            }else{
                cout << b[bb];
                bb++;
            }
        }
        cout << endl;
    }
    return 0;
}
