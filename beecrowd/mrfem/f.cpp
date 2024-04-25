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

    int n;
    string s, t, k;
    int p1 = 0;
    int p2 = 0;
    cin >> n;
    while (n--)
    {
        cin >> s >> t >> k;
        if (t[0] == '1') {
            p1 += k[1] - '0';
        } else {
            p2 += k[1] - '0';
        }
        //DBG(k[1]);
    }
    cout << p1 << " x " << p2 << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome