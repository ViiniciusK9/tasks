#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(2)<<(x)

int uri_2059(int argc, char const *argv[])
{   
    int p, j1, j2, r, a;
    cin >> p >> j1 >> j2 >> r >> a;

    if(p == 1){
        if(r == 1){
            if(a == 1){
                cout << "Jogador 2 ganha!" << endl;
            } else {
                cout << "Jogador 1 ganha!" << endl;
            }
        } else if(r == 0 && a == 1){
            cout << "Jogador 1 ganha!" << endl;
        } else {
            if((j1 + j2) % 2 == 0){
                cout << "Jogador 1 ganha!" << endl;
            } else {
                cout << "Jogador 2 ganha!" << endl;
            }
        }
    } else {
       if(r == 1){
            if(a == 1){
                cout << "Jogador 2 ganha!" << endl;
            } else {
                cout << "Jogador 1 ganha!" << endl;
            }
        } else if(r == 0 && a == 1){
            cout << "Jogador 1 ganha!" << endl;
        } else {
            if((j1 + j2) % 2 == 0){
                cout << "Jogador 2 ganha!" << endl;
            } else {
                cout << "Jogador 1 ganha!" << endl;
            }
        } 
    }
    return 0;
}
