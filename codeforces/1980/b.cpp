#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
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
    int n, f, k;
    vi v;
    cin >> t;
    while (t--)
    {
        cin >> n >> f >> k;
        v.clear();
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }

        int fav = -1;

        fav = v[f-1];

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());


        int op = -1;
        for (int i = 0; i < k; i++)
        {
            if (v[i] == fav) {
                op = 1;
            }
        }
        
        if (op == 1 && k < n && v[k] == fav) {
            op = 2;
        }

        if (op == 2) {
            cout << "MAYBE\n";
        } else if (op == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

        



    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome