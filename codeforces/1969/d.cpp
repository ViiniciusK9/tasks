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


vector<pi> vpi;

int solve(int i)
{
    if (i == vpi.size()) {
        return 
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, a1;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        vpi.clear();
        ll s1, s2;
        s1 = s2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a1;
            vpi.push_back({a1, 0});
            s1+= a1;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a1;
            vpi[i].second = a1;
            s2+= s1;
        }

        sort(vpi.begin(), vpi.end());
        reverse(vpi.begin(), vpi.end());

        for (int i = 0; i < k; i++)
        {
            
        }
        

        for (int i = k; i < vpi.size(); i++)
        {
            
        }
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome