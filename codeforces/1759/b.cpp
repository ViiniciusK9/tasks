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
        ll m, s;
        vi v;
        cin >> m >> s;
        ll sum = 0;
        set<int> st;
        for (int i = 0; i < m; i++)
        {
            int aux;
            cin >> aux;
            st.insert(aux);
            v.pb(aux);
        }

        sort(v.begin(), v.end());

        sum = 0;

        for (int i = 1; i <= *max_element(v.begin(), v.end()); i++)
        {
            if (st.find(i) == st.end()) {
                sum+=i;
            }
        }
        
        int segue = *max_element(v.begin(), v.end());
        segue++;
        while (sum < s)
        {
            sum += segue;
            segue++;
        }

        cout << (sum == s ? "YES\n" : "NO\n");
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome