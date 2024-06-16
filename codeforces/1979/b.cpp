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

    int t;

    cin >> t;
    int x, y;

    bitset<32> aux;


    while (t--)
    {
        cin >> x >> y;

        //cout << ((x ^ y)) << '\n';
        //cout << (((x) ^ (y))) << '\n';
        //cout << (bitset<32> (x ^ y)) << '\n';
        //cout << (bitset<32> (x)) << '\n';
        //cout << (bitset<32> (y)) << '\n';

        bitset<32> bx(x);
        bitset<32> by(y);
        ll t1 = 1;
        for (int i = 0; i < 32; i++)
        {
            if (bx[i] != by[i]) {
                cout << (1 << i);
                break;
            }

        }
        cout << '\n';

        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome