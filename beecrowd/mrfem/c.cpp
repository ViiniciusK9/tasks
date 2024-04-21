#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    int l, a;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;

    if (x1 == x2) {
        l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (y1 == y3) { 
            a = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        } else {
            a = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
        }
    } else if (x1 == x3) {
        l = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        if (y1 == y2) { 
            a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        } else {
            a = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
        }
    } else if (x1 == x4) {
        l = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
        if (y1 == y3) { 
            a = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        } else {
            a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
    }

    cout << (a*l) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome