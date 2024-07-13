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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, g, b;
    string c;

    cin >> r >> g >> b >> c;

    if (c == "Blue") {
        cout << min(r, g) << '\n';
    } else if (c == "Red") {
        cout << min(b, g) << '\n';
    } else {
        cout << min(r, b) << '\n';
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome