#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define fi first 
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
        int n;
        cin >> n;
        vi s(n);
        vi f(n);

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
        }

        int time = 0;

        for (int i = 0; i < n; i++)
        {
            cout << (i == 0 ? "" : " ") << abs(max(time, s[i]) - f[i]);
            time = f[i];
        }
        cout << '\n';
        
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome