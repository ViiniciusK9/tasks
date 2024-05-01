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

    int t, n, aux;
    vi p;

    cin >> t;

    while (t--)
    {
        cin >> n;
        p.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            p.PB(aux);
        }

        int t1 = 0;

        for (int i = 0; i < n; i++) {
            if (p[p[i]-1] == i+1) {
                t1 = 1;
                break;
            }
        }

        if (t1 == 1) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome