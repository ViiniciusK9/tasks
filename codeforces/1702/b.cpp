#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
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
        string s1;
        cin >> s1;
        ll ans = 1;

        set<char> st;

        for (int i = 0; i < s1.size(); i++)
        {
            st.insert(s1[i]);
            if (st.size() == 4)
            {
                ans++;
                st.clear();
                st.insert(s1[i]);
            } 
            
        }

        
        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome