#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>


using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int n, x, c = 0;
    cin >> n;
    int vet[100005];
    int veta[100005];
    int vetx[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vet[i] = x;
        veta[i] = x;
    
    }
    sort(vet, vet+n);
    for (int j = 0; j < n; j++){
        if (vet[j] != veta[j])
        {
            vetx[c] = veta[j];
            c++;
        }
        
    }
    if (c > 0){
        cout << c << endl;
        sort(vetx, vetx+c);
        for (int i = 0; i < c; i++){
            cout << vetx[i] << " ";
        }
        cout << endl;
    } else {
        cout << c << endl;
    }
    return 0;
}
