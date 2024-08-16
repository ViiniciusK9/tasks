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
        int n, k;
        cin >> n >> k;
        vi pref(n+1);
        string s1;
        cin >> s1;

        for (int i = 0; i < s1.size(); i++)
        {
            pref[i+1] = pref[i] + (s1[i] == 'B' ? 1 : 0);
        }

        int mx = 0;
        for (int i = 0; i < n-(k-1); i++)
        {
            mx = max(mx, pref[i+(k)] - pref[i]);
        }

        cout << k - mx << '\n';
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome