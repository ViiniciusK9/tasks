#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        if (n == k) {
            for (int i = 0; i < n-1; i++)
            {
                cout << "1 ";
            }
            cout << "1\n";
        } else if (k == 1) {
            for (int i = 1; i < n; i++)
            {
                cout << i << " ";
            }
            cout << n << '\n';
        } else {
            cout << "-1\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome