#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define se second 
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

    int t;
    cin >> t;

    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;
        //DBG(n);
        vector<ii> a(n);
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            //DBG(l);
            //DBG(r);
            a.pb({l, r});
        }
        bool ans = false;
        int ant = 0;
        for (auto el : a)
        {
            //DBG(abs(el.first - ant));
            if (abs(el.first - ant) >= s) {
                ans = true;
                break;
            }
            ant = el.second;
        }

        if (abs(a[a.size()-1].second - m) >= s) {
            ans = true;
        }

        cout << (ans ? "YES\n" : "NO\n");
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome