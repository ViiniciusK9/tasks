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

    int y;
    cin >> y;

    if (y % 4 != 0) {
        cout << "365\n";
    } else if (y%4 == 0 && y%100 != 0) {
        cout << "366\n";
    } else if (y%100 == 0 && y%400 != 0) {
        cout << "365\n";
    } else if (y % 400 == 0 ) {
        cout << "366\n";
    } else {
        cout << "365\n";
    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome