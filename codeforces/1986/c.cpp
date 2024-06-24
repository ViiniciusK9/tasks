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
    int n, m;
    string s1;
    string s2;
    vi v;
    int aux;
    while (t--)
    {
        v.clear();
        cin >> n >> m;
        cin >> s1;

        vector<char> v1;

        set<int> loc;

        for (int i = 0; i < m; i++)
        {
            cin >> aux;
            loc.insert(aux);
            //v.pb(aux);
        }

        cin >> s2;

        for (auto vi : loc)
        {
            //DBG(vi);
            v.pb(vi);
        }
        

        for (int i = 0; i < s2.size(); i++)
        {
            v1.pb(s2[i]);
        }

        sort(v1.begin(), v1.end());

        for (int i = v.size()-1; i >= 0; i--)
        {
            s1[v[i]-1] = v1[i];
        }

        cout << s1 << '\n';
        
        


        



    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome