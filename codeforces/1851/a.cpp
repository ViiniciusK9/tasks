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
        int n, m, k, h;
        cin >> n >> m >> k >> h;


        int aux;
        set<int> st;

        int step = 0;
        for (int i = 1; i < m; i++)
        {
            step += k;

            st.insert(step);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;

            if (st.find(abs(aux - h)) != st.end()) {
                ans++;
            }

        }

        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome