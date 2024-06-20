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

    int n;

    cin >> n;
    string s2;
    string ln, s1;
    getline(cin, ln);
    while (n--)
    {
        ln.clear();
        getline(cin, ln);
        
        
        set<string> st;
        for (int i = 0; i < ln.size(); i++)
        {
            if (ln[i] == ' ') {
                st.insert(s1);
                s1.clear();
            } else {
                s1.pb(ln[i]);
            }
        }
        st.insert(s1);
        s1.clear();
        int fir = 1;
        for (auto vi : st)
        {
            cout << (fir == 1 ? "" : " ")  << vi;
            fir = 0;
        }
        cout << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome