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

    int t;
    int n, aux, ans;
    map<int, int> m;

    cin >> t;

    while (t--)
    {
        cin >> n;
        m.clear();
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            m[aux]++;
        }
        
        for(auto i : m) {
            if (i.second >= 3) {
                ans += i.second / 3;
            }
            
        }

        cout << ans << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome