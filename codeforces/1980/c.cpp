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

    int t;

    cin >> t;
    int n;

    vi v1;
    vi v2;
    while (t--)
    {
        v1.clear();
        v2.clear();

        cin >> n;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v1.pb(aux);
        }

        for (int i = 0; i < n; i++)
        {  
            cin >> aux;
            v2.pb(aux);
        }
        int m;
        map<int, int> ma;
        cin >> m;

        int ult = -1;
        for (int i = 0; i < m; i++)
        {
            cin >> aux;
            if (i == m-1) {
                ult = aux;
            }
            ma[aux]++;
        }

        bool ans = true;
        int qnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v1[i] != v2[i]) {
                if (ma[v2[i]] >= 1) {
                    ma[v2[i]]--;
                    qnt++;
                } else {
                    ans = false;
                }
            }
        }

        if (ans && qnt < m) {
            ans = false;
            for (int i = 0; i < n; i++)
            {
                if (v2[i] == ult) {
                    ans = true;
                }
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