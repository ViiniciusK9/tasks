#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, x3, ans, m;
    cin >> x1 >> x2 >> x3;


    if (x1 >= x2 && x2 >= x3) {
        ans = abs(x1 - x2) + abs(x2 - x3);
    } else if (x3 >= x2 && x2 >= x1) {
        ans = abs(x1 - x2) + abs(x2 - x3);
    }else if (x2 >= x1 && x1 >= x3) {
        ans = abs(x1 - x2) + abs(x1 - x3);
    } else if (x3 >= x1 && x1 >= x2) {
        ans = abs(x1 - x2) + abs(x1 - x3);
    }else if (x2 >= x3 && x3 >= x1) {
        ans = abs(x1 - x3) + abs(x2 - x3);
    } else if (x1 >= x3 && x3 >= x2) {
        ans = abs(x1 - x3) + abs(x2 - x3);
    }
    cout << ans << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome