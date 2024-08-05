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
    int n, m, k;
    while (t--)
    {

        cin >> n >> m >> k;

        vi a;

        for (int i = 1; i <= n; i++)
        {
            if (i > m) {
                a.pb(i);
            }
        }

        reverse(a.begin(), a.end());

        for (int i = 1; i <= n; i++)
        {
            if (i <= m) {
                a.pb(i);
            }
        }

        //a.pb(m);

        bool f = true;
        for (auto el : a) {
            cout << (f == true ? "" : " ") << el;
            f = false;
        }
        cout << '\n';
        


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome