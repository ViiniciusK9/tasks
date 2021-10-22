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
    string a;
    int c = 0;
    cin >> a;
    char aux[a.size()];

    for(int i = 0; i < a.size(); i++){
        bool resp = false;
        for (int j = 0; j < a.size(); j++){
              
        if (resp){
            c = c;
        } else {
            aux[c] = a[i];
            c++;
        }
    }
    cout << aux << endl;
    cout << c << endl;
    if(c % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    } else{
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}
