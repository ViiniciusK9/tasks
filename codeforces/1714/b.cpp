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
        vi v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        set<int> st;
        int tam = 0;
        for (int i = n-1; i >= 0; i--)
        {
            st.insert(v[i]);
            if (st.size() == tam) {
                cout << n - st.size() << '\n';
                break;
            } else {
                tam++;
            }
        }

        if (tam == n) {
            cout << "0\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome