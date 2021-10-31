#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(){
    string a;
    int n;
    map<string, int> M;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(M.find(a) != M.end()){
            M[a]++;
        }else{
            M[a] = 1;
        }
    }
    

    for (map<string,int>::iterator it=M.begin(); it!=M.end(); ++it){
      cout<< it->first<< " aparece "<< it->second<< " vez(es)" << '\n';
    }
    
    return 0;
}
