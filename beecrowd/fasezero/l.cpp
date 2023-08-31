#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int mat[1123][1123];


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> mmm;
    int m, n, q, x, y, r, i_, j_, im, jm;
    cin >> n >> m;
    cin >> q;
    memset(mat, 0, sizeof(mat));
    long long int z = 0;
    while (q--)
    {
        cin >> x >> y >> r;
        x--;
        y--;
        if (x-r < 0)
        {
            i_ = 0;
        } else {
            i_ = x-r;
        }
        if (y-r < 0)
        {
            j_ = 0;
        } else {
            j_ = y-r;
        }
        if (x+r > n-1)
        {
            im = n-1;
        } else {
            im = x+r;
        }
        if (y+r > m-1)
        {
            jm = m-1;
        } else {
            jm = y+r;
        }
        
        im++;
        jm++;
        z += (abs(i_ - im) *abs(j_ - jm));

        /*
        for (int i = i_; i <= im; i++)
        {
            for (int j = j_; j <= jm; j++)
            {
                mat[i][j]++;
            }
        }
        */
    }

    cout << z / (n*m) << "\n";

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome