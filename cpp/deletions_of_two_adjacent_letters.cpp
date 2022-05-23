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
    int n, i, tam;
    char c;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        cin >> c;
        tam = s.length();
        //DBG(tam);
        //DBG(c);
        //DBG(s);
        if (tam % 2 == 0){
            cout << "NO\n";
        } else {
            for(i = 0; i < tam; i++){
                if (s[i] == c){
                    if((i+1) % 2 != 0){
                        //DBG(i+1);
                        //DBG(s[i]);
                        cout << "YES\n";
                        tam = 0;
                        break;
                    }
                }
            }
            if(tam){
                cout << "NO\n";
            }
        }
    }
    
    

    return 0;
}
