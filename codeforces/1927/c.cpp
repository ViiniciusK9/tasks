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
        int n, m, k;
        cin >> n >> m >> k;

        set<int> sa;
        set<int> sb;
        vi a;
        vi b;

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            if (aux <= k) {
                sa.insert(aux);
            }
        }

        int rep = 0;
        for (int i = 0; i < m; i++)
        {
            int aux;
            cin >> aux;
            if (sa.find(aux) != sa.end() & sb.find(aux) == sb.end()) {
                sb.insert(aux);
                rep++;
            } else if (aux <= k) {
                sb.insert(aux);
            }
        }

        for (auto el : sa)
        {
            a.pb(el);
        }
        
        for (auto el : sb)
        {
            b.pb(el);
        }
        
        if (sa.size() >= k/2 && sb.size() >= k/2) {

            for (auto el : sb)
            {
                sa.insert(el);
            }

            if (sa.size() == k) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            

        } else {
            cout << "NO\n";
        }

        /*
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }

        cout << "\n";

        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << '\n';
        cout << rep << '\n';

        */
        //cout << "\n";
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome