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

    int a, b, c;

    cin >> a >> b;

    if (a == 1) {
        if (b == 2) {
            cout << "3\n";
        } else if (b == 3) {
            cout << "2\n";
        } else {
            cout << "-1\n";
        }
    } else if (a == 2) {
        if (b == 1) {
            cout << "3\n";
        } else if (b == 3) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    } else if (a == 3) {
        if (b == 1) {
            cout << "2\n";
        } else if (b == 2) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome