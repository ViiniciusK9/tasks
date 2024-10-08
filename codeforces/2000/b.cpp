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

const int MAX = 2e5+10;

array<bool, MAX> vis;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vis.fill(false);    

        vi v(n);

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i == 0) {
                vis[v[i]] = true;
            } else {
                if (vis[v[i]-1] == false && vis[v[i]+1] == false) {
                    ans = false;
                }
                vis[v[i]] = true;
            }
        }

        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome