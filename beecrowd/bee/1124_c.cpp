#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, c, r1, r2;

    while (cin >> l >> c >> r1 >> r2)
    {
        if (l == 0) {
            break;
        }

        int px = r1;
        int py = r1;
        int ox = l-r2;
        int oy = c-r2;

        

        int re = pow(px-ox, 2) + pow(py - oy ,2);

        if (2*r1 <= l && 2*r2 <= c && 2*r2 <= l && 2*r1 <= c) {
            int ou = 1;
        } else {
            cout << "N\n";
            continue;
        }

        if (re >= pow(r1 + r2, 2)) {
            
            cout << "S\n";

        } else {
            cout << "N\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome