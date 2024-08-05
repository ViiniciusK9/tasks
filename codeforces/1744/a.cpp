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

    int n;
    string s1;

    cin >> t;
    vector<int> v;
    while (t--)
    {
        v.clear();
        cin >> n;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.pb(aux);
        }
        

        cin >> s1;
        set<char> st;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (v[i] == v[j]) {
                    st.insert(s1[j]);
                }
            }
            if (st.size() > 1) {
                flag = false;
            }
            st.clear();
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome