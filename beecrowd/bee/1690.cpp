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

set<ll> co;
vi v;
void solve(int i, ll sum) {
    if (i == v.size()) {
        co.insert(sum);
        return;
    }

    solve(i+1, sum);
    solve(i+1, sum+v[i]);
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux;
    
    cin >> t;
    while (t--)
    {
        v.clear();
        co.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.PB(aux);
        }
        solve(0, 0);
        int j = 0;
        for (auto i : co)
        {
            if (j != i) {
                cout << j << '\n';
                break;
            }
            j++;
        }
        if (j == co.size()) {
            cout << j << '\n';
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome