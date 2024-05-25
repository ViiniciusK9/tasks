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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, aux;

    cin >> n >> m;

    set<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        a.insert(aux);
        b.pb(aux);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        b.pb(aux);
    }
    

    sort(b.begin(), b.end());

    int ans = 0;
    int bant = (a.find(b[0]) != a.end() ? 1 : 0);
    for (int i = 1; i < b.size(); i++)
    {
        if (a.find(b[i]) != a.end())
        {
            if (bant == 1) {
                ans = -1;
                break;
            } else {
                bant = 1;
            }
        } else {
            bant = 0;
        }
    }

    if (ans == -1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome