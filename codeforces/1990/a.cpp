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
        int mx = 0;
        int qnt = 0;
        vi v;
        map<int, int> ma;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            ma[aux]++;
            mx = max(mx, aux);
            v.pb(aux);

        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] == mx) {
                qnt++;
            }

        }

        if (qnt%2 == 1) {
            cout << "YES\n";
        } else  {
            bool ans = false;

            for (auto el : ma)
            {
                if (el.second % 2 == 1) {
                    ans = true;
                }
            }

            if (ans) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome