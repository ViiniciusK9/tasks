#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 1 and y1 == 1 or x2 == 1 and y2 == 1)
        {
            cout << 2 << '\n';
        } else if (x1 == 1 and y1 == m or x2 == 1 and y2 == m) {
            cout << 2 << '\n';
        } else if (x1 == n and y1 == 1 or x2 == n and y2 == 1) {
            cout << 2 << '\n';
        } else if (x1 == n and y1 == m or x2 == n and y2 == m) {
            cout << 2 << '\n';
        } else if (y1 == 1 or x1 == 1 or y1 == m or x1 == n or y2 == 1 or x2 == 1 or y2 == m or x2 == n) {
            cout << 3 << '\n';
        } else {
            cout << 4 << '\n';
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome