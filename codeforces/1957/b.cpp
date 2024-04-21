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

    int t, n, k;
    vi v;
    
    cin >> t;
    while (t--)
    {
        v.clear();
        cin >> n >> k;
        int i = 1;
        int ant = i;
        while (i < k)
        {
            ant = i;
            i = i | i<<1;
        }
        //DBG(ant);
        if (n == 1) {
            cout << k << '\n';
        } else {
            
            v.push_back(ant);
            v.push_back(k-ant);
            for (int i = 2; i < n; i++)
            {
                v.push_back(0);
            }
            cout << v[0];
            for (int i = 1; i < n; i++)
            {
                cout << " " << v[i];
            }
            cout << '\n';
            
        }


        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome