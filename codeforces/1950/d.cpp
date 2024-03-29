#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    int a[] = {1, 2, 4, 8, 16, 32};
    vector<int> binary;
    cin >> t;
    bitset<6> aux;
    string temp;

    for (int i = 32; i > 1; i--)
    {
        k = 0;
        for (int j = 0; j < 6; j++)
        {
            if (i & a[j]) {
                k += pow(10, j);
            }
        } 
        //DBG(k);
        binary.push_back(k);
    }



    while (t--)
    {
        cin >> n;
        
        for (auto b : binary)
        {
            while (n%b == 0)
            {
                n /= b;
            }
        }
        if (n == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome