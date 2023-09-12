#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int x, y, z;
    double ans;

    cin >> x >> y >> z;

    if ((x * x) == (y*y) + (z*z)) 
    {
        // calcula area escura
        ans = (y * z) / 2.0;
        ans += (((z/2.0) * (z/2.0)) * 3.0) / 2.0;
        int r = ans;
        cout << "AREA = " << r << "\n";
    }
    else
    {
        // não é triagulo retangulo
        cout << "Nao eh retangulo!\n";
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome